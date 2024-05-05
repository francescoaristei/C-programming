# include <functional>
# include <iostream>
# include <chrono>
# include "active_object.h"

using namespace std;

ActiveObject::ActiveObject ()
    : t(&ActiveObject::run, this)
    , quit(false) {}


ActiveObject::~ActiveObject () {
    // if quit is true, destructor already executed
    if (quit.load()) 
        return; 
    quit.store(true);
    t.join();
}

void ActiveObject::run () {
    while (!quit.load()) {
        cout << "This method will be overwritten by the Reactor PriorityExecutor so any implementation is useless! ";
    }
}