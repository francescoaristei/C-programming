/*
A C++ module is composed of two files: priorityexecutor.h and priorityexecutor.cpp. These two
files contain a single C++ class, named PriorityExecutor that must have at least the following
public interface:

class PriorityExecutor
{
    public:
        PriorityExecutor();
        void execute(std::function<void ()> task, bool highPriority);
        ~PriorityExecutor();
};

This class should contain a thread that executes the tasks passed to it through the execute()
member function. Tasks have two priority levels, high and low. The tasks must not be executed
directly in the execute() member function, but rather passed to the background thread. The
background thread should execute each task in a run-to-completion fashion, and when it has finished
running a task, should both high and low priority tasks be waiting for execution, must always run all
the higher priority tasks first.
The destructor must wait for the (eventual) current task to complete and then join the thread
immediately disregarding (eventual) other tasks.
*/

// REACTOR design

# include <functional>
# include <iostream>
# include "priority_executor.h"

using namespace std;

void doNothing (){}

void PriorityExecutor::execute (function<void ()> task, bool highPriority) {
    if (highPriority) {
        highPriorityTasks.put(task);
    }
    else {
        lowPriorityTasks.put(task);
    }
}


PriorityExecutor::~PriorityExecutor () {
    quit.store(true);
    //execute(doNothing, 1);
    //execute(doNothing, 0);
    t.join();
}

void PriorityExecutor::run () {
    while (!quit.load()) {
        if (highPriorityTasks.size() != 0) {
            highPriorityTasks.get()();
        }
        else if (lowPriorityTasks.size() != 0) {
            lowPriorityTasks.get()();
        } 
    }
}