#include "utils.h"

using namespace std;
/*
  DFS 
     The key to code this question is how to represent queens properly
     1) Use a vector<int> queen to represent the queen's location:
          queen[i,j] means there is a queen placed in row i, column j
     2) Define a vector<int> columns_occupied :
           represent the columns where queens are placed
 */


bool isSafe(const vector<int> & queen, vector<int> & columns_occupied, int cur_row, int cur_col){
    // place queen on the same column?
    if(columns_occupied[cur_col]>0) return false;
    // place queen in diagonal ?
    // just check previous placed rows, that is, row_idx < cur_row
    for (int row_idx =0; row_idx<cur_row; row_idx++){
        int col_distance = abs(queen[row_idx] - cur_col);
        int row_distance = cur_row-row_idx;
        if(col_distance == row_distance) return false;
    }
    return true;
}

void dfs(int & total, vector<int> & queen, vector<int> & columns_occupied, int cur_row, int n){
    if(cur_row >= n){
        // all queens placed generate a solution and return
        total++;
        return;
    }
    // in current row, try all columns
    for(int j=0; j<n; j++){
        // if in current row, place a queen in column j is ok
        // then 1) place queen in board, 2) mark this column 3) start trying next row
        // otherwise, try next column
        if(isSafe(queen, columns_occupied, cur_row, j)){
            queen[cur_row] = j;
            columns_occupied[j] = 1;
            dfs(total, queen, columns_occupied, cur_row+1, n);
            columns_occupied[j] = 0;
        }
    }
}

int totalNQueens(int n) {
    int total = 0;
    vector<int> queen(n,0);
    vector<int> columns_occupied(n,0);
    int cur_row = 0;
    dfs(total, queen, columns_occupied, cur_row, n);
    return total;
}

int main(int argc, char *argv[]){
    cout<<totalNQueens(4)<<endl;;
    return 0;
}


