#include "TicTacToe.h"
#include <iostream>
#include <limits>

using namespace std;

TicTacToe::TicTacToe() : board(3, vector<char>(3, ' ')), currentPlayer('X') {}

void TicTacToe::displayBoard() const {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << (cell == ' ' ? '.' : cell) << " ";
        }
        cout << "\n";
    }
}

bool TicTacToe::isWinner(char player) const {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }
    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
           (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}

bool TicTacToe::isBoardFull() const {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

void TicTacToe::reset() {
    board.assign(3, vector<char>(3, ' '));
    currentPlayer = 'X';
}

int TicTacToe::minimax(bool isMaximizing) {
    if (isWinner('O')) return 10; // AI wins
    if (isWinner('X')) return -10; // Player wins
    if (isBoardFull()) return 0; // Draw

    if (isMaximizing) {
        int bestScore = numeric_limits<int>::min();
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                if (board[row][col] == ' ') {
                    board[row][col] = 'O';
                    int score = minimax(false);
                    board[row][col] = ' ';
                    bestScore = max(bestScore, score);
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = numeric_limits<int>::max();
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                if (board[row][col] == ' ') {
                    board[row][col] = 'X';
                    int score = minimax(true);
                    board[row][col] = ' ';
                    bestScore = min(bestScore, score);
                }
            }
        }
        return bestScore;
    }
}

pair<int, int> TicTacToe::findBestMove() {
    int bestScore = numeric_limits<int>::min();
    pair<int, int> bestMove = {-1, -1};

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (board[row][col] == ' ') {
                board[row][col] = 'O';
                int score = minimax(false);
                board[row][col] = ' ';
                if (score > bestScore) {
                    bestScore = score;
                    bestMove = {row, col};
                }
            }
        }
    }
    return bestMove;
}
void TicTacToe::playTwoPlayer() {
    reset();
    while (true) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        int row, col;
        cin >> row >> col;

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;
        if (isWinner(currentPlayer)) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        if (isBoardFull()) {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }
        currentPlayer = (currentPlayer == 'X' ? 'O' : 'X');
    }
}
void TicTacToe::playSinglePlayer() {
    reset();
    while (true) {
        displayBoard();
        if (currentPlayer == 'X') {
            cout << "Player X, enter your move (row and column): ";
            int row, col;
            cin >> row >> col;

            if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
                cout << "Invalid move. Try again.\n";
                continue;
            }
            board[row][col] = 'X';
        } else {
            cout << "AI is making a move...\n";
            auto [row, col] = findBestMove();
            board[row][col] = 'O';
        }

        if (isWinner(currentPlayer)) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        if (isBoardFull()) {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }
        currentPlayer = (currentPlayer == 'X' ? 'O' : 'X');
    }
}