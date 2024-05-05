// multiplication table of arbitrary dimension
# include <iostream>
# include <cstdlib>
# include <string>

using namespace std;

int** buildMultiplicationTable (int rows, int cols) {

    // the head points to an array of pointers
    int **head = new int*[rows];

    for (int i = 0; i < rows; i++) {
        // each row points to an one dimensional array of dimension: cols
        head[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            head[i][j] = i * j;
        }
    }

    return head;
}


void displayMultiplicationTable (int **head, int rows, int cols) {

    cout << "(" << "rows/cols" << ")";
    for (int j = 0; j < cols; j++) {
        string s = to_string(j);
        cout << "(    " << j;
        for (int i = 0; i < 4 - s.length(); i++) {
            cout << " ";
        }
        cout << ")";
    }

    cout << "\n";

    for (int i = 0; i < rows; i++) {
        string i_s = to_string(i);
        cout << "(    " << i;
        for (int t = 0; t < 4 - i_s.length(); t++) {
            cout << " ";
        }
        cout << ")";
        for (int j = 0; j < cols; j++) {
            string i_j = to_string(i*j);
            cout << "|    " << head[i][j];
            for (int z = 0; z < 4- i_j.length(); z++) {
                cout << " ";
            }
            cout << "|";
        }
        cout << "\n";
    }
}

int main () {
    int **head = NULL;
    int rows;
    int cols;

    cout << "Give the number of rows: ";
    cin >> rows;
    cout << "Give the number of cols: ";
    cin >> cols;

    // initialize the multiplication table
    head = buildMultiplicationTable(rows, cols);

    // display the multiplication table
    displayMultiplicationTable(head, rows, cols);


    // free the memory
    for (int i = 0; i < rows; i++) {
        delete[] head[i];
    }

    delete[] head;

    head = NULL;

}