#include <vector>

class Sudoku{

public:
    const int size = 9;
    int grid[size][size];

    Sudoku(){};

    void enterDigits() {

        for (int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                std::cin >>  this.grid[i][j] ;
            }
        }
    }

    void solve(){
        std::vector <int> posibles[this.size][this.size];
        int boxStartRow, boxStartCol;

        for (int col = 0; col < this.size; col++) {
            for(int row = 0; row < this.size; row++) {
                // find the empty cells
                if(this.grid[col][row] != 0){continue;}

                if(row < 3)     {boxStartRow = 0}
                else if(row < 6){boxStartRow = 3}
                else            {boxStartRow = 6}

                if(col < 3)     {boxStartCol = 0}
                else if(col < 6){boxStartCol = 3}
                else            {boxStartCol = 6}
                // fill the empty cell with all posible numbers
                for(int num = 1; num < 10; num++){
                    if(isInCol(col, num)){continue;}

                    if(isInRow(row, num)){continue;}

                    if(isInBox(boxStartRow, boxStartCol, num)){continue;}

                    posibles[col][row].insert(num);
                }
            }
        }

        // if there is only one posible number fill the grig with that number
        for (int col = 0; col < this.size; col++) {
            for(int row = 0; row < this.size; row++) {
                // find the empty cells
                if(this.grid[col][row] != 0){continue;}

            }
        }

    }

    void print(){
        for (int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                std::cout << this.grid[i][j] ;
            }
        }
    }

private:

    //check whether num is present in col or not
    bool isInCol(int col, int num){
       for (int row = 0; row < N; row++)
          if (this.grid[row][col] == num)
             return true;
       return false;
    }

    //check whether num is present in row or not
    bool isInRow(int row, int num){
       for (int col = 0; col < N; col++)
          if (this.grid[row][col] == num)
             return true;
       return false;
    }

    //check whether num is present in 3x3 box or not
    bool isInBox(int boxStartRow, int boxStartCol, int num){
       for (int row = 0; row < 3; row++)
          for (int col = 0; col < 3; col++)
             if (this.grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
       return false;
    }
}
