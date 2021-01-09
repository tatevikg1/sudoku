#include "Sudoku.hpp"
#include "gtest/gtest.h"

namespace {

    TEST(EnterDigits, Correct) {
        bool is_error = false;
        Sudoku sudoku;

        int input[9][9] = {
            5, 3, 0, 0, 7, 0, 0, 0, 0,
            6, 0, 0, 1, 9, 5, 0, 0, 0, 
            0, 9, 8, 0, 0, 0, 0, 6, 0,
            8, 0, 0, 0, 6, 0, 0, 0, 3,
            4, 0, 0, 8, 0, 3, 0, 0, 1,
            7, 0, 0, 0, 2, 0, 0, 0, 6,
            0, 6, 0, 0, 0, 0, 2, 8, 0,
            0, 0, 0, 4, 1, 9, 0, 0, 5,
            0, 0, 0, 0, 8, 0, 0, 7, 9
        };

        try {
            sudoku.enterDigits(input);
        } catch (const std::range_error& rt) {
            is_error = true;
        }
        EXPECT_FALSE(is_error);
    }

    TEST(EnterDigits, Negative) {
        bool is_error = false;
        Sudoku sudoku;

        int input[9][9] = {
            5, 3, 0, 0, 7, 0, 0, 0, 0,
            6, 0, 0, 1, 9, 5, 0, 0, 0, 
            0, 9, 8, -1, 0, 0, 0, 6, 0,
            8, 0, 0, 0, 6, 0, 0, 0, 3,
            4, 0, 0, 8, 0, 3, 0, 0, 1,
            7, 0, 0, 0, 2, 0, 0, 0, 6,
            0, 6, 0, 0, 0, 0, 2, 8, 0,
            0, 0, 0, 4, 1, 9, 0, 0, 5,
            0, 0, 0, 0, 8, 0, 0, 7, 9
        };

        try {
            sudoku.enterDigits(input);
        } catch (const std::range_error& rt) {
            is_error = true;
        }
        EXPECT_TRUE(is_error);
    }

    TEST(Solve, case1) {

        int input[9][9] = {
            5, 3, 0, 0, 7, 0, 0, 0, 0,
            6, 0, 0, 1, 9, 5, 0, 0, 0, 
            0, 9, 8, 0, 0, 0, 0, 6, 0,
            8, 0, 0, 0, 6, 0, 0, 0, 3,
            4, 0, 0, 8, 0, 3, 0, 0, 1,
            7, 0, 0, 0, 2, 0, 0, 0, 6,
            0, 6, 0, 0, 0, 0, 2, 8, 0,
            0, 0, 0, 4, 1, 9, 0, 0, 5,
            0, 0, 0, 0, 8, 0, 0, 7, 9
        };
        int result[9][9] = {
            5, 3, 4, 6, 7, 8, 9, 1, 2, 
            6, 7, 2, 1, 9, 5, 3, 4, 8, 
            1, 9, 8, 3, 4, 2, 5, 6, 7, 
            8, 5, 9, 7, 6, 1, 4, 2, 3, 
            4, 2, 6, 8, 5, 3, 7, 9, 1, 
            7, 1, 3, 9, 2, 4, 8, 5, 6, 
            9, 6, 1, 5, 3, 7, 2, 8, 4, 
            2, 8, 7, 4, 1, 9, 6, 3, 5, 
            3, 4, 5, 2, 8, 6, 1, 7, 9 
        };
        
        Sudoku sudoku;
        sudoku.enterDigits(input);
        sudoku.solve();

        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                EXPECT_EQ(sudoku.grid[i][j], result[i][j]);
            }
        }

    }

     TEST(Solve, case2) {

        int input[9][9] = {
            3, 0, 0, 8, 0, 1, 0, 0, 2,
            2, 0, 1, 0, 3, 0, 6, 0, 4,
            0, 0, 0, 2, 0, 4, 0, 0, 0,
            8, 0, 9, 0, 0, 0, 1, 0, 6,
            0, 6, 0, 0, 0, 0, 0, 5, 0,
            7, 0, 2, 0, 0, 0, 4, 0, 9,
            0, 0, 0, 5, 0, 9, 0, 0, 0,
            9, 0, 4, 0, 8, 0, 7, 0, 5,
            6, 0, 0, 1, 0, 7, 0, 0, 3
        };
        int result[9][9] = {
            3, 4, 6, 8, 9, 1, 5, 7, 2, 
            2, 9, 1, 7, 3, 5, 6, 8, 4, 
            5, 7, 8, 2, 6, 4, 3, 9, 1, 
            8, 5, 9, 4, 7, 3, 1, 2, 6, 
            4, 6, 3, 9, 1, 2, 8, 5, 7, 
            7, 1, 2, 6, 5, 8, 4, 3, 9, 
            1, 3, 7, 5, 4, 9, 2, 6, 8, 
            9, 2, 4, 3, 8, 6, 7, 1, 5, 
            6, 8, 5, 1, 2, 7, 9, 4, 3 
        };
        
        Sudoku sudoku;
        sudoku.enterDigits(input);
        sudoku.solve();

        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                EXPECT_EQ(sudoku.grid[i][j], result[i][j]);
            }
        }

    }


    
} 

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
