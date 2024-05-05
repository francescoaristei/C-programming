# include <iostream>
# include <functional>
# include "execute.h"
# include <thread>
# include <chrono>


using namespace std;

void task (int counter) {
    //this_thread::sleep_for(chrono::seconds(1));
    cout << "This is the task number: " << counter << "\n";
}

void callback (int counter) {
    //this_thread::sleep_for(chrono::seconds(1));
    cout << "This is the callback number: " << counter << "\n";
}


int main () {
    int counterTask = 0;
    int counterCallback = 0;
    Execute e;
    int counter;

    int loop = 1;

    while (counterTask < 100) {
        // important to sleep the main thread, otherwise the background thread finds always the mutex locked
        this_thread::sleep_for(chrono::seconds(3));
        e.executeAndCallback(bind(&task, counterTask++), bind(&callback, counterCallback++));
    }
}