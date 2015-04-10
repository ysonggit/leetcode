#include <gtest/gtest.h>
#include "utils.h"
using namespace std;

void dfs(vector<vector<char> > &grid, vector<vector<int> > &visited, int i, int j){
    int n = grid.size();
    int m = grid[0].size();
    if(i==n || i<0 || j==m || j<0) return;
    if(visited[i][j]==1) return;
    if(grid[i][j]=='0') return;
    if(grid[i][j]=='1') visited[i][j] = 1;
    dfs(grid, visited, i+1, j);
    dfs(grid, visited, i, j+1);
    dfs(grid, visited, i-1, j);
    dfs(grid, visited, i, j-1);
}
    
int numIslands(vector<vector<char>> &grid) {
    int n = grid.size();
    if(n==0) return 0;
    int m = grid[0].size();
    vector<vector<int> > visited(n, vector<int>(m, 0));
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]=='1' && visited[i][j] ==0){
                dfs(grid, visited, i, j);
                count++;
            }
        }
    }
    return count;
}

TEST(Island, I){
    vector<string> strs{"11000","11000","00100","00011"};
    vector<vector<char> > grid;
    for(string s: strs){
        vector<char> line;
        for(char c: s){
            line.push_back(c);
        }
        grid.push_back(line);
    }
    int res = 3;
    ASSERT_EQ(res, numIslands(grid));
}

TEST(Island, II){
    vector<string> strs{"11110","11010","11000","00000"};
    vector<vector<char> > grid;
    for(string s: strs){
        vector<char> line;
        for(char c: s){
            line.push_back(c);
        }
        grid.push_back(line);
    }
    int res = 1;
    ASSERT_EQ(res, numIslands(grid));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}