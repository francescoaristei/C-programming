// Three dimensional multiplication tables: an array where each value is a multiplication table (two dimensional array)

# include <cstdlib>
# include <iostream>
# include <string>

using namespace std;

int** getTwoDimArray (int rows, int cols) {

    // each element is a pointer
    int **head = new int*[rows];

    for (int i = 0; i < rows; i++) {
        head[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            head[i][j] = i * j;
        }
    }

    return head;
}


int*** getThreeDimArray (int length, int rows, int cols) {
    // allocate the memory for the array of mult tables
    // each element of this array is a pointer to pointer
    int ***head = new int**[length];

    for (int i = 0; i < length; i++) {
        head[i] = getTwoDimArray(rows, cols);
    }

    return head;
}

void displayTwoDimArray(int **head, int rows, int cols) {
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


void displayThreeDimArray(int ***head, int length, int rows, int cols) {
    cout << "-------------------------------------------------------";
    cout << "\n";
    for (int i = 0; i < length; i++) {
        displayTwoDimArray(head[i], rows, cols);
        cout << "\n";
        cout << "-------------------------------------------------------";
        cout << "\n";
    }
}



int main () {
    // head of the three dimensional array
    int ***head = NULL;

    int length;
    int rows;
    int cols;

    cout << "Set the number of multiplication tables: ";
    cin >> length;
    cout << "Set the number of rows of each multiplication table: ";
    cin >> rows;
    cout << "Set the number of cols of each multiplication table: ";
    cin >> cols;

    head = getThreeDimArray(length, rows, cols);

    displayThreeDimArray(head, length, rows, cols);

    // First delete memory pointed by each pointer
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < rows; j++) {
            delete[] head[i][j];
        }
    }

    // Second delete memory pointed by each pointer of pointers
    for (int i = 0; i < length; i++) {
        delete[] head[i];
    }

    // Finally delete memory pointed by the pointer of pointers of pointers
    delete head;

    head = NULL;
}
