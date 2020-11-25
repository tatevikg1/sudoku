#pragma once

#include <vector>
#include <iostream>

class Sudoku{

private:

    static const int size = 9;
    int grid[size][size];

    std::vector <int> posibles[size][size];
    int boxStartRow, boxStartCol;
    bool solved = false;

public:

    Sudoku();

    void enterDigits();

    void solve();

    void print();


    // find all posibitities
    void findAllPosibleNumbers();

    // fill found numbers
    void fillFoundNumbers();

    // check whether num is present in column or not
    bool isInCol(int col, int num);

    //check whether num is present in row or not
    bool isInRow(int row, int num);

    //check whether num is present in 3x3 box or not
    bool isInBox(int boxStartRow, int boxStartCol, int num);
};
