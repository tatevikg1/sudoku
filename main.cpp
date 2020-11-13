#include <iostream>
#include "sudoku.cpp"

int main() {
    Sudoku sudoku;

    std::cout << "Enter input. \n";

    sudoku.enterDigits();

    sudoku.solve();

    std::cout << "\n";

    sudoku.print();

}
