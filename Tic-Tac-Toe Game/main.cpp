#include "TicTacToe.h"
#include <iostream>

using namespace std;

int main() {
    TicTacToe game;
    int choice;

    do {
        cout << "\nTic-Tac-Toe\n";
        cout << "1. Two-Player Game\n";
        cout << "2. Single-Player Game (Play Against AI)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            game.playTwoPlayer();
        } else if (choice == 2) {
            game.playSinglePlayer();
        } else if (choice != 3) {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    cout << "Thanks for playing Tic-Tac-Toe!\n";
    return 0;
}