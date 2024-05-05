# include <mutex>
# include <condition_variable>
# include <list>
# include <functional>
# include <atomic>
# include "delayed_executor.h"
# include <thread>
# include <chrono>

using namespace std;

void doNothing () {}


DelayedExecutor::DelayedExecutor ()
    : t(&DelayedExecutor::run, this)
    , done(false) {}


DelayedExecutor::~DelayedExecutor () {
    done.store(true);
    push(doNothing);
    t.join();
}

void DelayedExecutor::run () {
    bool isTask = false;
    function<void ()> task;
    {
        unique_lock<mutex> lck(m);
        while (!done.load()) {
            if (!queue.empty()) {
                task = queue.front();
                queue.pop_front();
                isTask = true;
            }
            else {
                cv.wait(lck);
            }
        }
    }
    if (isTask) {
        // it is correct to use this_thread and not t because the run method will be executed on the thread t
        // therefore when this_thread is called, it refers to the t thread.
        this_thread::sleep_for(chrono::seconds(10));
        task();
    }
}

void DelayedExecutor::push (function<void ()> task) {
    unique_lock<mutex> lck(m);
    queue.push_back(task);
    cv.notify_one();
}