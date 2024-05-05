/*

You are required to implement a library function in a file called execute.cpp with the
signature:
void executeAndCallBack(std::function<void ()> task,
std::function<void ()> callback);
and associated data structures that, the first time it is called, creates a thread that first
executes the task and then calls the callback. After it has completed, the thread shall not
terminate, and instead be reused for the same purpose in successive calls to the same
function, in order to avoid the overhead of thread creation/termination. The function
executeAndCallBack() may be called also while a task is running, and this case the
passed tasks and callbacks need to be queued for execution by the same background
thread.

*/

// Reactor Design

# include "execute.h"
# include <iostream>
# include <thread>
# include <functional>
# include <mutex>
# include <condition_variable>
# include <list>

using namespace std;

Execute::Execute () 
    : quit(false)
    , t(&Execute::run, this)
    {}

Execute::~Execute () {
    {
        unique_lock<mutex> lck(m);
        quit = true;
        cv.notify_one();
    }
    t.join();
}

void Execute::executeAndCallback (function<void ()> task, function<void ()> callback) {
    unique_lock<mutex> lck(m);
    tasks.push_back(task);
    callbacks.push_back(callback);
    cv.notify_one();
}

void Execute::run () {
    function<void ()> task;
    function<void ()> callback;
    bool found = false;
    bool askedToQuit = false;
    do {
        {
            unique_lock<mutex> lck(m);
            if (quit) {
                askedToQuit = true;
            }
            else if (!tasks.empty() && !callbacks.empty()) {
                task = tasks.front();
                tasks.pop_front();
                callback = callbacks.front();
                callbacks.pop_front();
                found = true;
            }
            // wait on the lock
            else {
                cv.wait(lck);
            }
        }
        if (found) {
            task();
            callback();
        }    
    } while (!askedToQuit);
}

