#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>
#include <string>

class TicTacToe {
private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

    bool isWinner(char player) const;
    bool isBoardFull() const;
    void displayBoard() const;

    int minimax(bool isMaximizing);
    std::pair<int, int> findBestMove();

public:
    TicTacToe();
    void reset();
    void playTwoPlayer();
    void playSinglePlayer();
};

#endif 