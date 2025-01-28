#include "Sudoku.h"
#include <iostream>

using namespace std;

void sudokuCLI() {
    Sudoku sudoku;
    int choice;

    do {
        cout << "\nSudoku Solver and Validator\n";
        cout << "1. Load puzzle from file\n";
        cout << "2. Display puzzle\n";
        cout << "3. Validate puzzle\n";
        cout << "4. Solve puzzle\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string filename;
            cout << "Enter filename: ";
            cin >> filename;
            sudoku.loadFromFile(filename);
        } else if (choice == 2) {
            sudoku.printGrid();
        } else if (choice == 3) {
            if (sudoku.isValid()) {
                cout << "The puzzle is valid.\n";
            } else {
                cout << "The puzzle is invalid.\n";
            }
        } else if (choice == 4) {
            sudoku.solve();
            sudoku.printGrid();
        }
    } while (choice != 5);
}

int main() {
    sudokuCLI();
    return 0;
}