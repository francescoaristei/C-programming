# include <cstdlib>
# include <iostream>

using namespace std;


int main () {
    int **head = NULL;

    int rows;
    int cols;

    cout << "Set the number of rows: ";
    cin >> rows;
    cout << "Set the number of cols: ";
    cin >> cols;

    head = new int* [rows];

    for (int i = 0; i < rows; i++) {
        head[i] = new int [cols];
    }

    cout << "Print out each address of each cell of the two dim array:" << "\n";

    // As expected, each array of cols dim has all the elements contiguous, while the different arrays
    // are laid out in different parts of the memory between each others.
    for (int i = 0; i < rows; i++) {
        cout << "-------------" << "\n";
        for (int j = 0; j < cols; j++) {
            cout << &head[i][j];
            cout << "\n";
        }
    }
}