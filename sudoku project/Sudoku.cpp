#include "Sudoku.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

Sudoku::Sudoku() : grid(SIZE, vector<int>(SIZE, 0)) {}

bool Sudoku::isValidPlacement(int row, int col, int num) {
    // Check row
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == num) return false;
    }
    // Check column
    for (int i = 0; i < SIZE; i++) {
        if (grid[i][col] == num) return false;
    }
    // Check 3x3 subgrid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == num) return false;
        }
    }
    return true;
}

bool Sudoku::solveSudoku() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) { // Find an empty cell
                for (int num = 1; num <= SIZE; num++) {
                    if (isValidPlacement(row, col, num)) {
                        grid[row][col] = num; // Place the number
                        if (solveSudoku()) return true; // Recurse
                        grid[row][col] = 0; // Backtrack
                    }
                }
                return false; // No valid number found
            }
        }
    }
    return true; // Solved
}

void Sudoku::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file.\n";
        return;
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            file >> grid[i][j];
        }
    }
    file.close();
    cout << "Puzzle loaded successfully.\n";
}

void Sudoku::printGrid() const {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            cout << (grid[row][col] ? to_string(grid[row][col]) : ".") << " ";
        }
        cout << "\n";
    }
}

bool Sudoku::isValid() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (grid[row][col] != 0) {
                int num = grid[row][col];
                grid[row][col] = 0; // Temporarily remove number
                if (!isValidPlacement(row, col, num)) {
                    grid[row][col] = num; // Restore number
                    return false;
                }
                grid[row][col] = num; // Restore number
            }
        }
    }
    return true;
}

void Sudoku::solve() {
    if (solveSudoku()) {
        cout << "Sudoku solved successfully!\n";
    } else {
        cout << "Failed to solve Sudoku.\n";
    }
}