#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to display the game board
void displayBoard(const vector<vector<char>> &board) {
    for (const auto &row : board) {
        for (const auto &cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check for a win
bool checkWin(const vector<vector<char>> &board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check for a draw
bool checkDraw(const vector<vector<char>> &board) {
    for (const auto &row : board) {
        for (const auto &cell : row) {
            if (cell == '-') {
                return false;
            }
        }
    }
    return true;
}

// Main function for the game
int main() {
    char playAgain;
    do {
        vector<vector<char>> board(3, vector<char>(3, '-'));
        char currentPlayer = 'X';
        bool gameWon = false;

        cout << "Welcome to Tic-Tac-Toe!\n";

        while (true) {
            displayBoard(board);

            // Player input
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            // Validate move
            if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != '-') {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            // Update board
            board[row - 1][col - 1] = currentPlayer;

            // Check for win or draw
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!\n";
                gameWon = true;
                break;
            } else if (checkDraw(board)) {
                displayBoard(board);
                cout << "The game is a draw!\n";
                break;
            }

            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        // Ask to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing Tic-Tac-Toe!\n";
    return 0;
}
