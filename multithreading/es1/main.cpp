# include <iostream>
# include "priority_executor.h"
# include <chrono>
# include <functional>

using namespace std;

void printAdd (int a, int b) {
    this_thread::sleep_for(chrono::seconds(5));
    cout << a << "+" << b << "=" << a + b << "\n";
}

int main () {
    PriorityExecutor pe;
    int a, b;
    int loop = 1;
    while (loop) {
        cout << "Set a: ";
        cin >> a;
        cout << "Set b: ";
        cin >> b;
        pe.execute(bind(&printAdd, a, b), 1);
        cout << "1 to continue, 0 to exit: ";
        cin >> loop;
    }
}