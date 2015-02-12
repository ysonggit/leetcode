#include "utils.h"
#include <gtest/gtest.h>

using namespace std;

/*
  use the first row and first column to mark if need to set zeros
  for example
  1 3 4 0 7    0 0 0 0 0
  1 3 4 5 8 -> 1 3 4 0 0 
  2 3 2 9 0    0 0 0 0 0
  4 4 8 5 1    4 4 8 0 0

  1. go through first row and col
     if there exists any 0
     mark boolean values set_first_row and set_first_col true
  2. go through the rest rows and cols
     if find a zero at M(i,j)
     mark M(i,0) and M(0,j) 0
  3. re-check the first row and col
     if 0 found, set entire row and col zeroes
  4. finally set first row/col zeros if marked at step 1
 */

void setZeroes(vector<vector<int> > &matrix) {
    if(matrix.size()==0) return ;
    int m = matrix.size();
    int n = matrix[0].size();
    auto it = find(matrix[0].begin(), matrix[0].end(), 0);
    bool set_first_row = (it != matrix[0].end()) ? true : false;
    bool set_first_col = false;
    for(int i=0; i<m; i++){
        if(matrix[i][0] == 0){
            set_first_col = true;
            break;
        }
    }
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(matrix[i][j]==0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for(int i=1; i<n; i++){
        if(matrix[0][i] == 0) {
            // set current column zeroes
            for(int r=0; r<m; r++){
                matrix[r][i] = 0;
            }
        }
    }
    for(int i=1; i<m; i++){
        if(matrix[i][0]==0){
            // set current row zeroes
            for(int & k: matrix[i]) k = 0;
        }
    }
    if(set_first_row) {
        for(int & k : matrix[0]) k = 0;
    }
    if(set_first_col) {
        for(int r=0; r<m; r++){
            matrix[r][0] = 0;
        }
    }
}

int main(int argc, char *argv[]){
    vector<vector<int> > matrix = {
        {1, 3, 4, 0, 7},
        {1, 3, 4, 5, 8},
        {2, 3, 2, 9, 0},
        {4, 4, 8, 5, 1}
    };
    setZeroes(matrix);
    print2DVector(matrix);
    return 0;
}

