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

    Sudoku(){};

    void enterDigits() {

        for (int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                std::cin >> grid[i][j] ;
            }
        }

    };

    void solve(){

        while(!solved){
            findAllPosibleNumbers();
            fillFoundNumbers();
        }

    };

    void print(){
        for (int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                std::cout << grid[i][j] << " ";
            }
            std::cout << "\n";
        }
    };


// find all posibitities
    void findAllPosibleNumbers(){
        for (int row = 0; row < size; row++) {
            for(int col = 0; col < size; col++) {
                // find the empty cells
                if(grid[row][col] != 0){continue;}

                if(row < 3)     {boxStartRow = 0;}
                else if(row < 6){boxStartRow = 3;}
                else            {boxStartRow = 6;}

                if(col < 3)     {boxStartCol = 0;}
                else if(col < 6){boxStartCol = 3;}
                else            {boxStartCol = 6;}

                // fill the empty cell with all posible numbers
                for(int num = 1; num < 10; num++){
                    if(isInCol(col, num)){continue;}

                    if(isInRow(row, num)){continue;}

                    if(isInBox(boxStartRow, boxStartCol, num)){continue;}

                    posibles[row][col].push_back(num);
                }
            }
        }
    };

// fill found numbers
    void fillFoundNumbers(){

        solved = true;

        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(posibles[i][j].size() == 1){
                    grid[i][j] = posibles[i][j].back();
                    solved = false;
                }
                posibles[i][j].clear();
            }
        }
    };

// check whether num is present in column or not
    bool isInCol(int col, int num){
        for (int row = 0; row < size; row++){
            if (grid[row][col] == num){
                return true;
            }
        }
        return false;
    }

//check whether num is present in row or not
    bool isInRow(int row, int num){
        for (int col = 0; col < size; col++){
            if (grid[row][col] == num){
                return true;
            }
        }
        return false;
    }

//check whether num is present in 3x3 box or not
    bool isInBox(int boxStartRow, int boxStartCol, int num){
        for (int row = 0; row < 3; row++){
            for (int col = 0; col < 3; col++){
                if (grid[row+boxStartRow][col+boxStartCol] == num){
                    return true;
                }
            }
        }
        return false;
    }
};
