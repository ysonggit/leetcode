#include "utils.h"
#include <gtest/gtest.h>
using namespace std;
/*
  idea: do dfs starting from every single letter in the grid
        trick: use a 2d matrix to record visited position
        if current char in board is not equal to the char in the target word
        or if current char in board is already visited, then return false
 */
// i and j are row and column indices of the starting letter
// cur_idx is the index of current letter in given word
bool dfs(const vector<vector<char> > &board,
    const string& word,
    vector<vector<int> > & visited,
    int i, int j,
    int cur_idx)
{
    if(i<0 || i>=board.size() || j>= board[0].size() || j<0 ) return false;
    if(visited[i][j] != 0) return false;
    if(board[i][j] != word[cur_idx] ) return false;
    if(cur_idx == word.length()-1 && word[cur_idx]==board[i][j]) return true;
    bool res = false;
    visited[i][j] = 1;
    // search four directions
    res = dfs(board, word, visited,  i+1, j, cur_idx+1)
        || dfs(board, word, visited, i, j+1, cur_idx+1)
        || dfs(board, word, visited, i-1, j, cur_idx+1)
        || dfs(board, word, visited, i, j-1, cur_idx+1);
    visited[i][j] = 0; // donot forget this!

    return res;
}

bool exist(vector<vector<char> > &board, string word) {
    int rows = board.size();
    if(rows==0) return word.empty();
    int cols = board[0].size();
    vector<vector<int> > visited(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(dfs(board, word, visited,  i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}

vector<vector<char> > board{
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
};

TEST(WordSearch, I){
    string word("ABCCED");
    ASSERT_EQ(true, exist(board, word));
}

TEST(WordSearch, II){
    string word("SEE");
    ASSERT_EQ(true, exist(board, word));
}

TEST(WordSearch, III){
    string word("ABCB");
    ASSERT_EQ(false, exist(board, word));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

