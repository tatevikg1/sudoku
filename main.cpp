#include <iostream>
#include "Sudoku.hpp"

int main() {
    
    Sudoku sudoku;

    std::cout << "Enter sudoku input numbers (0 for empty cells). \n";

    sudoku.enterDigits();

    sudoku.solve();

    std::cout << "\n";

    sudoku.print();

}
