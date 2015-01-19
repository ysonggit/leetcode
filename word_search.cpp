#include "utils.h"
#include <gtest/gtest.h>
using namespace std;
/*
  idea: do dfs starting from every single letter in the grid
        trick: use a 2d matrix to record visited position
 */
// r and c are row and column indices of the starting letter
// cur_idx is the index of current letter in given word
bool dfs(const vector<vector<char> > &board, const string& word, int r, int c, int cur_idx, vector<vector<int> > & visited){
    if(r<0 || r>=board.size() || c<0 || c>=board[0].size() ) return false;
    char cur = word[cur_idx];
    if(cur != board[r][c] || visited[r][c] == 1 )  return false;
    if(visited[r][c] == 0 && cur == board[r][c] && cur_idx ==word.length()-1){
        return true;
    }

    bool res = false;
    if(cur == board[r][c]){
        visited[r][c] = 1;
        res = dfs(board, word, r+1, c, cur_idx+1, visited) ||
            dfs(board, word, r-1, c, cur_idx+1, visited) ||
            dfs(board, word, r, c+1, cur_idx+1, visited) ||
            dfs(board, word, r, c-1, cur_idx+1, visited);
        visited[r][c] = 0;
    }
    return res;
}

bool exist(vector<vector<char> > &board, string word) {
    if(board.size()==0) return false;
    int rows = board.size();
    int cols = board[0].size();
    vector<vector<int> > visited(rows, vector<int>(cols, 0));
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(dfs(board, word, i, j, 0, visited)){
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char *argv[]){
    // testing::InitGoogleTest(&argc, argv);
    vector<vector<char> > board{
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    //print2DVector(board);
    string words[] ={"ABCCED", "SEE", "ABCB"};
    for(int i=0; i<3; i++){
        if(exist(board, words[i])){
            cout<<"Exist!"<<endl;
        }else{
            cout<<"Does not exist."<<endl;
        }
    }
    return 0;
}

