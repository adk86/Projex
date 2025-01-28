#ifndef SUDOKU_H
#define SUDOKU_H

#include <vector>
#include <string>

class Sudoku {
private:
    static const int SIZE = 9;                  
    std::vector<std::vector<int>> grid;        

    bool isValidPlacement(int row, int col, int num); 
    bool solveSudoku();                         

public:
    Sudoku();                                    

    void loadFromFile(const std::string& filename);   
    void printGrid() const;                         
    bool isValid();                                 
    void solve();                                   
};

#endif // SUDOKU_H