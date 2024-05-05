// maze generator

# include <cstdlib>
# include <iostream>
# include <ctime>

using namespace std;

string** initializeMaze (int rows, int cols) {
    string **head = new string* [rows];
    for (int i = 0; i < rows; i++) {
        head[i] = new string[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            head[i][j] = '-';
        }
    }

    return head;
}

bool isNotValid (int row, int col, int rows, int cols) {
    if ((row < 0 || row >= rows) || (col < 0 || col >= cols)) {
        return true;
    }
    return false;
}

bool notIn (int alreadyUsed[], int pick) {
    for (int i = 0; i < 4; i++) {
        if (alreadyUsed[i] != pick) {
            return true;
        }
    }
    return false;
}

void displayMaze(string **head, int rows, int cols) {

    for (int i = 0; i < rows; i++) {
        cout << "|";
        for (int j = 0; j < cols; j++) {
            cout << head[i][j];
        }
        cout << "|";
        cout << "\n";
    }
}

void DFS (string **head, int rows, int cols, int row, int col) {
    if (isNotValid(row, col, rows, cols)) {
        return;
    }

    if (head[row][col] == " ") {
        return;
    }

    int counter = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (!(isNotValid(i, j, rows, cols)) && (i == row || j == col) && !(i == row && j == col)) {
                if (head[i][j] == " ") {
                    counter += 1;
                }
            }
        }
    }

    if (counter > 1) {
        return;
    }

    head[row][col] = " ";

    // move randomly to each neighbor of cell (row, col) and apply the same reasoning

    int neighbors[4][2];
    int possibilities[4][2] = {{row, col - 1}, {row - 1, col}, {row, col + 1}, row + 1, col};
    int alreadyUsed[4] = {-1, -1, -1, -1};

    // randomly fill neighbors with the possibilities
    int pick;
    int fillCounter = 0;
    while (fillCounter <= 3) {
        pick = (rand() % 4) + 0;
        if (notIn(alreadyUsed, pick)) {
            neighbors[fillCounter][0] = possibilities[pick][0];
            neighbors[fillCounter][1] = possibilities[pick][1];
            alreadyUsed[fillCounter] = pick;
            fillCounter ++;
        }
    }


    // now move to the neighbors
    for (int i = 0; i < 4; i++) {
        DFS(head, rows, cols, neighbors[i][0], neighbors[i][1]);
    }
}


int main () {
    int rows;
    int cols;
    string **head = NULL;
    srand(time(NULL));
    cout << "Set heigth: ";
    cin >> rows;
    cout << "Set width: ";
    cin >> cols;
    head = initializeMaze(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            DFS(head, rows, cols, i, j);
        }
    }

    displayMaze(head, rows, cols);

    for (int i = 0; i < rows; i++) {
        delete [] head[i]; 
    }

    delete head;
}