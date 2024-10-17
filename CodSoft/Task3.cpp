#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void displayBoard(const vector<vector<char>>& board);
bool checkWin(const vector<vector<char>>& board, char player);
bool checkDraw(const vector<vector<char>>& board);
void switchPlayer(char& currentPlayer);
void playGame();

int main() {
    char playAgain;
    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    return 0;
}

// Function to display the board
void displayBoard(const vector<vector<char>>& board) {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---------\n";
    }
    cout << "\n";
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == ' ') return false;
    return true;
}

// Function to switch the current player
void switchPlayer(char& currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to handle the game logic
void playGame() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    int row, col;
    bool gameWon = false;

    while (true) {
        displayBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the input is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        // Update the board
        board[row - 1][col - 1] = currentPlayer;

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            gameWon = true;
            break;
        }

        // Check if the game is a draw
        if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!\n";
            break;
        }

        // Switch to the other player
        switchPlayer(currentPlayer);
    }
}
