# include <iostream>
# include <vector>


using namespace std;


template <typename T>
T sumValues (vector<T> values) {
    T result = 0;

    for (int i = 0;i < values.size(); i++) {
        result += values[i];
    }

    return result;
}

int main () {
    vector<int> vecInt;
    vector<double> vecDouble;
    vector <float> vecFloat;

    int loopInt = 1;

    while (loopInt) {
        int value;
        cout << "Set a value: ";
        cin >> value;
        vecInt.push_back(value);
        cout << "1 to continue, 0 to exit: ";
        cin >> loopInt;
    }

    cout << "The result of the sum is: " << sumValues<int>(vecInt) << "\n";

    int loopDouble = 1;

    while (loopDouble) {
        double value;
        cout << "Set a value: ";
        cin >> value;
        vecDouble.push_back(value);
        cout << "1 to continue, 0 to exit: ";
        cin >> loopDouble;
    }

    cout << "The result of the sum is: " << sumValues<double>(vecDouble) << "\n";

    float loopFloat = 1;

    while (loopFloat) {
        float value;
        cout << "Set a value: ";
        cin >> value;
        vecFloat.push_back(value);
        cout << "1 to continue, 0 to exit: ";
        cin >> loopFloat;
    }

    cout << "The result of the sum is: " << sumValues<float>(vecFloat) << "\n";
}