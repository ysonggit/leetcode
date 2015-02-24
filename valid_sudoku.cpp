#include "utils.h"
#include <gtest/gtest.h>

using namespace std;
/*
http://stackoverflow.com/questions/5111434/sudoku-validity-check-algorithm-how-does-this-code-works
it uses an int flag (initially set to zero) as a "bit array";
for each value, it checks if the corresponding bit in the flag is set,
and if it's not, it sets it.

If, instead, that bit position is already set,
it knows that the corresponding value has already been seen,
so the piece of Sudoku is invalid.

*/
bool isValidSudoku(vector<vector<char> > & board){
    // board empty? 
    const int n = board.size();
    vector<int> col_flags(n, 0);
    vector<int> box_flags(n, 0);
    for(int i=0; i<n; i++){
        // elements in the same row needs a flag
        int row_flag = 0;
        for(int j=0; j<n; j++){
            if(board[i][j]!='.'){
                // for numbers 1 to 9
                // prepare a bit mask by shift the 1 left 0 to 8 bits 
                int bit = 1<< (board[i][j]-'1');
                // sub-grid rowIdx = 3*(grid_idx/3) + cell_idx/3
                //int r = i/3*3+j/3, c = i%3*3+j%3;
                int box_idx = i/3*3 + j/3;
                // row_flag & bit != 0  --- will be evaluated  (row_flag & (bit !=0 ))
                if(row_flag & bit || col_flags[j] & bit || box_flags[box_idx] & bit ){
                    return false;
                }
                row_flag |= bit;
                col_flags[j] |= bit;
                box_flags[box_idx] |= bit;
            }
        }
    }
    return true;
}

TEST(Sudoku, I){
    vector<string> rows ={
        "..5.....6","....14...",".........",".....92..","5....2...",".......3.","...54....","3.....42.","...27.6.."
    };
    vector<vector<char> > board;
    for_each(rows.begin(), rows.end(), [&board](string & row){
            vector<char> v;
            for_each(row.begin(), row.end(), [&v](char & c){v.push_back(c); });
            board.push_back(v);
        } );
    print2DVector(board);
    bool res = true;
    ASSERT_EQ(res, isValidSudoku(board));
 }

TEST(Sudoku, II){
    vector<string> rows ={
       "7...4....","...865...",".1.2.....",".....9...","....5.5..",".........","......2..",".........","........."
    };
    vector<vector<char> > board;
    for_each(rows.begin(), rows.end(), [&board](string & row){
            vector<char> v;
            for_each(row.begin(), row.end(), [&v](char & c){v.push_back(c); });
            board.push_back(v);
        } );
    print2DVector(board);
    bool res = false;
    ASSERT_EQ(res, isValidSudoku(board));
 }

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
