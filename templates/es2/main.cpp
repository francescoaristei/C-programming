# include <cstdlib>
# include <iostream>
# include "es1.h"

using namespace std;


int main () {
    int dim;
    cout << "Set a dim: ";
    cin >> dim;
    // non empty constructor
    vectorOfTypes<int> v1(dim);
    vectorOfTypes<int> *v1p = new vectorOfTypes<int>(dim);
    // copy operator (the compiler understands)
    vectorOfTypes v2 = v1;
    // assignment operator
    vectorOfTypes<int> v3;
    v3 = v1;
    // copy operator
    vectorOfTypes v4(v1);
    cout << "Choose an option: " << "\n";

    int option;
    do {
        cout << "1: set an element" << "\n";
        cout << "2: get an element" << "\n";
        cout << "3: push element in the back" << "\n";
        cout << "4: push element in the front" << "\n";
        cout << "5: display array" << "\n";
        cout << "6: exit" << "\n";
        cout << "Option: ";

        int index;
        int value;
        cin >> option;
        switch (option) {
            case 1:
                cout << "Choose an index: ";
                cin >> index;
                cout << "Choose a value: ";
                cin >> value;
                v2.setValue(index, value);
                break;
            case 2:
                cout << "Choose an index: ";
                cin >> index;
                cout << "The value at index " << index << " is: " << v2.getValue(index) << "\n";
                break;
            case 3:
                cout << "Choose the element to push in the back: ";
                cin >> value;
                v2.pushBack(value);
                v2.displayVector();
                break;
            case 4:
                cout << "Choose the element to push in the front: ";
                cin >> value;
                v2.pushFront(value);
                v2.displayVector();
                break;
            case 5:
                cout << "The array is: ";
                v2.displayVector();
                break;
            case 6:
                cout << "Exiting..." << "\n";
                break;
            default:
                cout << "Option is not valid!" << "\n";
                break;
        }
    } while (option != 6);
}