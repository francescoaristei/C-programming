# include <iostream>
# include <vector>

using namespace std;

template <typename T>
vector<T> sort (vector<T> vec) {

    // insertion sort!
    for (int i = 1; i < vec.size(); i++) {
        T key = vec[i];
        int j = i - 1;
        while (j > 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = key;
    }

    return vec;
}

template <typename T>
void displayVector (vector<T> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << "\n";
}

int main () {
    vector<char> vecChar;
    int addChar = 1;

    while (addChar) {
        char c;
        cout << "Set a char: ";
        cin >> c;
        vecChar.push_back(c);
        cout << "1 to continue, 0 to exit: ";
        cin >> addChar;
    }

    displayVector<char>(vecChar);

    cout << "The sorted version of the vector is: ";
    vector<char> sorted = sort<char>(vecChar);
    displayVector(sorted);
}