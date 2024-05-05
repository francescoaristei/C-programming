# include <iostream>
# include <vector>


using namespace std;

// multiple types because otherwise items of vec and value must be of the same type.
template<typename T, typename D>
bool search (vector<T> vec, D value) {
    // NOTE: is_same evaluated at COMPILE time! (type cannot be specified when running the program)
    if (is_same<T, D>::value) {
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == value) {
                return true;
            }
        }
        cout << "Value not in the vector!" << "\n";
        return false;
    }
    cout << "Value and vector of different types! " << "\n";
    return false;
}

int main () {
    vector<int> vecInt;
    double d;

    int addInt = 1;
    while (addInt) {
        int value;
        cout << "Set new int: ";
        cin >> value;
        vecInt.push_back(value);
        cout << "1 to continue, 0 to exit: ";
        cin >> addInt;
    }

    cout << "Set a double: ";
    cin >> d;

    if (search(vecInt, d)) {
        cout << "Double " << d << " found in the vec!" << "\n";
    }

    int i;
    cout << "Set an integer: ";
    cin >> i;

    if (search(vecInt, i)) {
        cout << "Integer " << i << " found in the vec!" << "\n";
    }
}