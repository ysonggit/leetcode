#include <gtest/gtest.h>
#include "utils.h"
using namespace std;
/*
   idea : brute-force (DFS)
   fill spot one by one,
   first finish one row, then move to next row until the last row
   given board
        "..5.....6"
        "....14..."
        "........."
        ".....92.."
        "5....2..."
        ".......3."
        "...54...."
        "3.....42."
        "...27.6.."
   for a spot waiting for a number, try 1..9,
   (by calling valid sudoku procedure),
   if the number is ok for current spot, then try next spot
   otherwise, try another number at this spot

 */

bool isValid(vector<vector<char> > & board, int i, int j){
    for(int k=0; k<9; k++) {
        if(board[i][k]==board[i][j] && k != j) return false; // dup number on same row
        if(board[k][j]==board[i][j] && k != i) return false; // dup number on same col
    }
    for(int sub_row_idx = i/3*3; sub_row_idx < i/3*3+3; sub_row_idx++){
        for(int sub_col_idx = j/3*3; sub_col_idx < j/3*3+3; sub_col_idx++){
            if(i!= sub_row_idx && j!= sub_col_idx 
                && board[i][j]==board[sub_row_idx][sub_col_idx]) return false;
        }
    }
    return true;
}

bool dfs(vector<vector<char> >& board, int i, int j){
    if(j>=9) return dfs(board, i+1, 0);
    if(i==9) return true;
    if(board[i][j]=='.'){
        // try filling each number in the cell
        for(int k=0; k<9; k++){
            board[i][j] = (char) (k+'1');
            if(isValid(board, i, j)){
                if (dfs(board, i, j+1)) return true;
            }
            board[i][j] = '.';
        }
    }else{ 
        return dfs(board, i, j+1);
    }
    return false;
}

void solveSudoku(vector<vector<char> > &board) {
    if(board.empty() ) return ;
    dfs(board, 0, 0);
}

TEST(test_case, I){
       vector<string> rows ={
        "..5.....6",
        "....14...",
        ".........",
        ".....92..",
        "5....2...",
        ".......3.",
        "...54....",
        "3.....42.",
        "...27.6.."
    };
    vector<vector<char> > board;
    for_each(rows.begin(), rows.end(), [&board](string & row){
            vector<char> v;
            for_each(row.begin(), row.end(), [&v](char & c){v.push_back(c); });
            board.push_back(v);
        } );
    print2DVector(board);
    solveSudoku(board);
    print2DVector(board);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


