# include <iostream>
# include <thread>
# include <mutex>
# include <condition_variable>
# include <atomic>
# include <list>
# include <vector>
# include "file_transformer.h"


using namespace std;

void doNothing () {}

ThreadPool::ThreadPool (unsigned int thread_number) : done(false)
{   
    if (threadCount <= 0) {
        threadCount = thread::hardware_concurrency();
    }
    else {
        threadCount = thread_number;
    }

    for (int i = 0; i < threadCount; ++i) {
        workers.push_back(thread(&ThreadPool::executeTask, this));
    }
}

ThreadPool::~ThreadPool () {
    done.store(true);
    // NOTE: the unique_lock here is an error: the lock is already taken in the pushTask method, in this way 
    // there is a deadlock because the internal lock (the one on pushTask) remains blocked by the fact that
    // the mutex is already taken by the calling function (this destructor).
    // {
    // unique_lock<mutex> lck(m);
    for (int i = 0; i < threadCount; ++i) {
        pushTask(&doNothing);
    }
    //}
    
    for (int i = 0; i < threadCount; ++i){
        workers[i].join();
    }
}


void ThreadPool::pushTask (function<void ()> task) {
    unique_lock<mutex> lck(m);
    queue.push_back(task);
    cv.notify_one();
}

void ThreadPool::executeTask () {
    bool isTask = false;
    function<void ()> task;
    do {
        {
            unique_lock<mutex> lck(m);
            if (!queue.empty()) {
                isTask = true;
                task = queue.front();
                queue.pop_front();
            }
            else {
                cv.wait(lck);
            }
        }
        // IMPORTANT: execute with the mutex unlocked to leverage thread pool!
        if (isTask) {
            // execute task
            task();
        }
    } while (!done.load());
}