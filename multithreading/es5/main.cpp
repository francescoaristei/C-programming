# include <thread>
# include <iostream>
# include "sync_point.h"

using namespace std;

SyncPoint<int> sp;


void consume () {
    for(;;) {
        list <int> data = sp.getData();
        cout << "The consumed numbers are: " << *data.begin() << *next(data.begin(), 1) << *next(data.begin(), 2)  << "\n";
    }
}

int main () {
    thread t(&consume);
    while (1) {
        int value;
        cout << "Produce a number: ";
        cin >> value;
        sp.addData(value);
    }

    t.join();
}