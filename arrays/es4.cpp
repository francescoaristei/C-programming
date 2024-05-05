# include <cstdlib>
# include <iostream>
# include <ctime>

using namespace std;

// Tic-Tac-Toe program, if the game is unwinnable, it should be detected immediately.

// Each time a player makes a move, it checks if the player has won
bool hasWon (char board[][3], int row, int col) {

    // check if the row has all the same value
    bool checkRow = true;
    char valueRow = board[row][col];
    for (int i = 0; i < 3; i++) {
        if (board[row][i] != valueRow) {
            checkRow = false;
            break;
        }
    }
    if (checkRow) {
        return checkRow;
    }

    // check if the col has all the same value
    bool checkCol = true;
    char valueCol = board[row][col];
    for (int j = 0; j < 3; j++) {
        if (board[j][col] != valueCol) {
            checkCol = false;
            break;
        }
    }
    if (checkCol) {
        return checkCol;
    }

    bool checkDiag = false;
    // check the diagonals (only if the value written is on a diagonal)
    if (row == col || (row == 0 && col == 2) || (row == 2 && col == 0)) {
        if (board[0][0] == board[1][1] == board[2][2]) {
            checkDiag = true;
            return checkDiag;
        }
        if (board[2][0] == board[0][0] == board[2][0]) {
            checkDiag = true;
            return checkDiag;
        }
    }

    return false;
}

bool isEven(char board[][3]) {
    bool check = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                check = false;
            }
        }
    }
    return check;
}

void drawBoard (char board[][3]) { 
    cout << "-------------\n"; 
    for (int i = 0; i < 3; i++) { 
        cout << "| "; 
        for (int j = 0; j < 3; j++) { 
            cout << board[i][j] << " | "; 
        } 
        cout << "\n-------------\n"; 
    } 
} 

// computationally intensive: executed for each move (for each cell) --> 0(n^2)
bool isWinnable (char board[][3]) {

    // check for a winnable row
    for (int i = 0; i < 3; i++) {
        char rowValue = ' ';
        bool winRow = true;
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                continue;
            }
            else {
                if (rowValue != ' ') {
                    if (rowValue != board[i][j]) {
                        winRow = false;
                        break;
                    }
                }
                else {
                    rowValue = board[i][j];
                }
            }
        }
        if (winRow) {
            return true;
        }
    }

    // check for a winnable col
    for (int i = 0; i < 3; i++) {
        char colValue = ' ';
        bool winCol = true;
        for (int j = 0; j < 3; j++) {
            if (board[j][i] == ' ') {
                continue;
            }
            else {
                if (colValue != ' ') {
                    if (colValue != board[i][j]) {
                        winCol = false;
                        break;
                    }
                }
                else {
                    colValue = board[i][j];
                }
            }
        }
        if (winCol) {
            return true;
        }
    }

    // check for a winnable diagonal
    char diagValue = ' ';
    bool winDiag = true;

    for (int i = 0; i < 3; i++) {
        if (board[i][i] == ' ') {
            continue;
        }
        else {
            if (diagValue != ' ') {
                if (diagValue != board[i][i]) {
                    winDiag = false;
                    break;
                }
            }
            else {
                diagValue = board[i][i];
            }
        }
    }

    if (winDiag) {
        return true;
    }

    char adiagValue = ' ';
    bool winAdiag = true;

    for (int i = 0; i < 3; i++) {
        if (board[3-i][i] == ' ') {
            continue;
        }
        else {
            if (adiagValue != ' ') {
                if (adiagValue != board[i][i]) {
                    winAdiag = false;
                    break;
                }
            }
            else {
                adiagValue = board[i][i];
            }
        }
    }

    if (winAdiag) {
        return true;
    }
    return false;

}


int main () {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    // random number either 1 or 2 to choose who starts to play;
    // from there, the players alternate.
    srand(time(NULL));
    int player = (rand() % 2) + 1;
    bool play = true;
    cout << "The tic-tac-toe game can start!" << "\n";
    drawBoard(board);

    while (play) {
        int row;
        int col;
        cout << "The player " << player << " makes a move" << "\n";
        cout << "Choose the row of the cell you want to write:" << "\n";
        cin >> row;
        cout << "Choose the col of the cell you want to write" << "\n";
        cin >> col;
        if (board[row][col] != ' ') {
            cout << "Choose another cell, this one has already been written." << "\n";
            continue;
        }
        else {
            cout << "Cell: " << "[" << row << "," << col << "]" << " written" << "\n";
            if (player == 1) {
                board[row][col] = 'X';
            } 
            else {
                board[row][col] = 'O';
            }
            drawBoard(board);
            if (hasWon(board, row, col)) {
                    cout << "Congrats player " << player << " you have won!";
                    break;
            }
            if (isEven(board)) {
                cout << "You're even, there are no winners!" << "\n";
                break;
            }

            if (!(isWinnable(board))) {
                cout << "The game is not winnable anymore, restart the game!" << "\n";
                break;
            }
            // players need to alternate.
            if (player == 1) {
                player = 2;
            }
            else {
                player = 1;
            }
        }
    }
}



