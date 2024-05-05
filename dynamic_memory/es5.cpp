// connect 4 board (simplified version: no diagonals)

# include <cstdlib>
# include <iostream>
# include <ctime>

using namespace std;

string** buildGrid (int rows, int cols) {
    string **head = NULL;
    head = new string* [rows];
    for (int i = 0; i < rows; i++) {
        head[i] = new string[cols];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            head[i][j] = "_";
        }
    }
    return head;
}

void displayGrid (string **head, int rows, int cols, int user, bool win) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << head[i][j] << " ";
        }
        cout << "\n";
    }

    if (!(win)) {
        cout << "Congratulation user " << user << " you have won!" << "\n";
    }
}

bool checkWinning (string **head, int row, int col, int rows, int cols) {
    int counterR = 0;
    int prevRow = row - 1;

    // from the cell downward on the same col
    for (int i = row; i < rows; i++) {
        if (head[i][col] == head[row][col] && prevRow == i - 1 && head[i][col] != "_") {
            counterR += 1;
            prevRow = i;
        }
        if (counterR == 4) {
            return false;
        }
    }


    int counterCL = 0;
    int prevColL = col + 1;
    // from the cell going backward on the left on the same row
    for (int i = col; i >= 0; i--) {
        if (head[row][i] == head[row][col] && prevColL == i + 1 && head[row][i] != "_") {
            counterCL += 1;
            prevColL = i;
        }
        if (counterCL == 4) {
            return false;
        }
    }

    int counterCR = 0;
    int prevColR = col - 1;
    // from the cell going forward on the right on the same row
    for (int i = col; i < cols; i++) {
        if (head[row][i] == head[row][col] && prevColR == i - 1 && head[row][i] != "_") {
            counterCR += 1;
            prevColR = i;
        }
        if (counterCR == 4) {
            return false;
        }
    }

    return true;
}

int main () {

    string **head = NULL;
    int rows;
    int cols;
    srand(time(NULL));

    cout << "Set number of rows: ";
    cin >> rows;
    cout << "Set number of cols: ";
    cin >> cols;

    // initialize grid
    head = buildGrid(rows, cols);

    bool finish = true;
    int user = (rand() % 2) + 1;

    // array that keeps track of level of fill for each column
    int *indexes = new int[cols];
    for (int i = 0; i < cols; i++) {
        indexes[i] = rows - 1;
    }

    while (finish) {
        int col;
        cout << "User " << user << ", set  col: ";
        cin >> col;
        if (indexes[col] < 0) {
            cout << "Full column, change column." << "\n";
        }
        else {
            if (user == 1) {
                head[indexes[col]][col] = "+";
            }
            else {
                head[indexes[col]][col] = "x";
            }
            finish = checkWinning(head, indexes[col], col, rows, cols);
            indexes[col] -= 1;
        }
        displayGrid(head, rows, cols, user, finish);
        if (user == 1) {
            user = 2;
        }
        else {
            user = 1;
        }
    }

    // free memory
    for (int i = 0; i < rows; i++) {
        delete [] head[i];
    }

    delete head;
    head = NULL;
}

