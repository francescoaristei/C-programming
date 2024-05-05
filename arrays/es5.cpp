# include <cstdlib>
# include <iostream>
# include <ctime>

using namespace std;

// Connect-4 program.

// max-size, will be modified by the user
const int MAX_SIZE = 10;

// Each time a player makes a move, it checks if the player has won
bool hasWon (char board[][MAX_SIZE], int row, int col, int dimension) {

    // check if the row has all the same value
    bool checkRow = false;
    char valueRow = board[row][col];
    int rowCounter = 0;
    int j_0 = 0;
    int j_1 = 0;
    while (j_1 < dimension) {
        if (board[row][j_1] == valueRow && board[row][j_1] == board[row][j_0]) {
            rowCounter ++;
        }
        else {
            j_1 = j_1 + 1;
        }
        j_0 = j_1;
        j_1 ++;

        if (rowCounter == 4) {
            checkRow = true;
        }
    }
    if (checkRow) {
        return checkRow;
    }


    // check if the col has all the same value
    bool checkCol = false;
    char valueCol = board[row][col];
    int colCounter = 0;
    int i_0 = 0;
    int i_1 = 0;
    while (i_1 < dimension) {
        if (board[i_1][col] == valueCol && board[i_1][col] == board[i_0][col]) {
            colCounter ++;
        }
        else {
            i_1 = i_1 + 1;
        }
        i_0 = i_1;
        i_1 ++;

        if (colCounter == 4) {
            checkCol = true;
        }
    }
    if (checkCol) {
        return checkCol;
    }


    // check if the diag has all the same value
    bool checkDiag = false;
    char valueDiag = board[row][col];
    int diagCounter = 0;
    int d_0 = 0;
    int d_1 = 0;
    while (d_1 < dimension) {
        if (board[d_1][d_1] == valueDiag && board[d_1][d_1] == board[d_0][d_0]) {
            diagCounter ++;
        }
        else {
            d_1 = d_1 + 1;
        }
        d_0 = d_1;
        d_1 ++;

        if (diagCounter == 4) {
            checkDiag = true;
        }
    }
    if (checkDiag) {
        return checkDiag;
    }



    // check if the anti diag has all the same value
    bool checkAdiag = false;
    char valueAdiag = board[row][col];
    int adiagCounter = 0;
    int ad_0 = 0;
    int ad_1 = 0;
    while (ad_1 < dimension) {
        if (board[dimension - ad_1][ad_1] == valueAdiag && board[dimension - ad_1][ad_1] == board[dimension - ad_0][ad_0]) {
            adiagCounter ++;
        }
        else {
            ad_1 = ad_1 + 1;
        }
        ad_0 = ad_1;
        ad_1 ++;

        if (adiagCounter == 4) {
            checkAdiag = true;
        }
    }
    if (checkAdiag) {
        return checkAdiag;
    }


    return false;
}

bool isEven(char board[][MAX_SIZE], int dimension) {
    bool check = true;
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            if (board[i][j] == ' ') {
                check = false;
            }
        }
    }
    return check;
}

void drawBoard (char board[][MAX_SIZE]) { 
    cout << "-----------------------------------------\n"; 
    for (int i = 0; i < MAX_SIZE; i++) { 
        cout << "| "; 
        for (int j = 0; j < MAX_SIZE; j++) { 
            cout << board[i][j] << " | "; 
        } 
        cout << "\n-----------------------------------------\n"; 
    } 
} 



int main () {
    char board[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    // random number either 1 or 2 to choose who starts to play;
    // from there, the players alternate.
    srand(time(NULL));
    int player = (rand() % 2) + 1;
    bool play = true;
    cout << "The tic-tac-toe game can start!" << "\n";
    drawBoard(board);

    // The player that does not start, chooses the dimensions of the board
    if (player == 1) {
        cout << "Player " << 2 << " decides the dimensions of the board" << "\n"; 
    }
    else {
        cout << "Player " << 1 << " decides the dimensions of the board" << "\n"; 
    }

    int dimension;
    cin >> dimension;
    

    while (play) {
        int row;
        int col;
        cout << "The player " << player << " makes a move" << "\n";
        cout << "Choose the row of the cell you want to write (be it less than " << dimension << ")" << "\n";
        cin >> row;
        cout << "Choose the col of the cell you want to write (be it less than " << dimension << ")" << "\n";
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
            if (hasWon(board, row, col, dimension)) {
                    cout << "Congrats player " << player << " you have won!";
                    break;
            }
            if (isEven(board, dimension)) {
                cout << "You're even, there are no winners!" << "\n";
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



