#include <iostream>
#include "Sudoku.hpp"
#include <exception>


int main() {

    Sudoku sudoku;

    system("clear");

    std::cout << "Enter sudoku input numbers (0 for empty cells). \n";

    try{
        sudoku.enterDigits();

        sudoku.solve();

        std::cout << "\n";

        sudoku.print();

    }catch(const std::range_error& e){

        std::cerr << e.what() << "\n";
    }




}
