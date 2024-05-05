# include <thread>
# include <mutex>
# include <condition_variable>
# include <list>
# include <functional>
# include <iostream>
# include "background_worker.h"

using namespace std;

void doNothing () {}


BackgroundWorker::BackgroundWorker ()
    : t(&BackgroundWorker::consumer, this)
    , quit(false)
    {}


BackgroundWorker::~BackgroundWorker() {
    quit.store(true);
    // it is needed because if the destructor is called, store is set to true. Then t.join() is executed.
    // However, if the thread is waiting because the queue was empty, it remains waiting until someone wakes it up
    // therefore the t.join() waits indefinitely as well, and the destructor never finishes. By adding an empty task
    // the thread is woken up, resuming execution from the cv.wait and evaluating the quit as true, exiting the while loop.
    add(&doNothing);
    t.join();
}

void BackgroundWorker::add (function<void ()> func) {
    unique_lock<mutex> lck(m);
    queue.push_back(func);
    cv.notify_one();
}

void BackgroundWorker::consumer () {
    bool isTask = false;
    function<void ()> task;
    {
        unique_lock<mutex> lck(m);
        while (!quit.load()) {
            if (!queue.empty()) {
                task = queue.front();
                queue.pop_front();
                isTask = true;
            }
            else {
                // NOTE: when the thread is woken up with the notify_one() it resumes execution from this point of the code
                // where it was waiting.
                cv.wait(lck);
            }
        }
    }
    if (isTask) {
        task();
    }
}