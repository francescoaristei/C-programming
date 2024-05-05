# include <cstdlib>
# include <iostream>


using namespace std;


class Board {

    public:
        bool getHasWin();
        char** getBoard();
        void initializeBoard(int rows, int cols);
        void makeMove(int x, int y, char symbol);
        void setRows(int rows);
        void setCols(int cols);

    private:
        char **board;
        int rows;
        int cols;
        bool hasWin = false;
        int getRows();
        int getCols();
        bool checkWin(int x, int y, char symbol); 
        void displayBoard();
        void freeMemory();
};

int Board::getRows () {
    return rows;
}

int Board::getCols () {
    return cols;
}


void Board::makeMove (int x, int y, char symbol) {
    if ((x >= 0 && x < getRows()) && (y >= 0 && y < getCols())) {
        if (board[x][y] == '*') {
            board[x][y] = symbol;
        }
        else {
            cout << "Invalid move, the cell is already filled!" << "\n";
        }
    }
    else {
        cout << "Invalid move, the board has not been updated!" << "\n";
    }

    displayBoard();

    if (checkWin(x, y, symbol)) {
        hasWin = true;
        freeMemory();
    }
}

bool Board::checkWin (int x, int y, char symbol) {
    bool col = false;
    int colCounter = 0;
    char prevCol = symbol;
    for (int i = 0; i < getRows(); i++) {
        if (board[i][y] == symbol && board[i][y] == prevCol) {
            colCounter += 1;
        }
        else {
            colCounter = 0;
        }
        prevCol = board[i][y];
        if (colCounter == 3) {
            col = true;
            break;
        }
    }

    if (col) {
        return col;
    }

    bool row = false;
    int rowCounter = 0;
    char prevRow = symbol;
    for (int i = 0; i < getCols(); i++) {
        if (board[x][i] == symbol && board[x][i] == prevRow) {
            rowCounter += 1;
        }
        else {
            rowCounter = 0;
        }
        prevRow = board[x][i];
        if (rowCounter == 3) {
            row = true;
            break;
        }
    }
    if (row) {
        return row;
    }

    bool dDiag = false;
    int dDiagCounter = 0;
    char prevdDiag = symbol;
    for (int i = 0; i < getCols(); i++) {
        if (board[i][i] == symbol && board[i][i] == prevdDiag) {
            dDiagCounter += 1;
        }
        else {
            dDiagCounter = 0;
        }
        prevdDiag = board[i][i];
        if (dDiagCounter == 3) {
            dDiag = true;
            break;
        }
    }

    if (dDiag) {
        return dDiag;
    }

    bool iDiag = false;

    int iDiagCounter = 0;
    char previDiag = symbol;
    for (int i = 0; i < getCols(); i++) {
        if (board[i][getCols() - i] == symbol && board[i][getCols() - i] == previDiag) {
            iDiagCounter += 1;
        }
        else {
            iDiagCounter = 0;
        }
        previDiag = board[i][getCols() - i];
        if (iDiagCounter == 3) {
            iDiag = true;
            break;
        }
    }
    if (iDiag) {
        return iDiag;
    }

    return false;
}

bool Board::getHasWin () {
    return hasWin;
}

void Board::initializeBoard (int rows, int cols) {
    board = new char*[rows];
    for (int i = 0; i < rows; i++) {
        board[i] = new char[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = '*';
        }
    }
}

char** Board::getBoard() {
    return board;
}


void Board::displayBoard () {
    for (int i = 0; i < getRows(); i++) {
        for (int j = 0; j < getCols(); j++) {
            cout << board[i][j] << "  ";
        }
        cout << "\n";
    }
}

void Board::freeMemory() {
    for (int i = 0; i < getRows(); i++) {
        delete board[i];
    }

    delete board;
}

void Board::setRows (int irows) {
    rows = irows;
}

void Board::setCols (int icols) {
    cols = icols;
}

int main () {
    Board b;
    int dim;
    int rows;
    int cols;
    cout << "Set the number of rows and columns: ";
    cin >> dim;
    rows = dim;
    cols = dim;
    b.setRows(rows);
    b.setCols(cols);

    b.initializeBoard(rows, cols);

    int user = 1;
    int play = 1;

    while (play) {
        int row;
        int col;
        cout << "Choose a row between 0 and " << rows - 1 << ": ";
        cin >> row;
        cout << "Choose a col between 0 and " << cols - 1 << ": ";
        cin >> col;
        cout << "User " << user << " fill the cell: " << "(" << row << "," << col << ")" << "\n";
        char symbol;
        if (user == 1) {
            symbol = 'o';
        }
        else {
            symbol = 'x';
        }
        b.makeMove(row, col, symbol);
        if (b.getHasWin()) {
            cout << "Congratulation user " << user << ", you are the winner! " << "\n";
            break;
        }
        if (user == 1) {
            user = 2;
        }
        else {
            user = 1;
        }
    }
}