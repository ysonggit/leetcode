#include <gtest/gtest.h>
#include "utils.h"
using namespace std;
/*
  given a maze represented as a 2D square matrix
  # represents free space, B represents block
  ##BB##
  #B####
  ####B#
  #BBB##
  B###B#
  place a robot at the upper left corner, it can move towards four directions
  write a function to check if there exits a way to the lower right corner
 */

bool dfs(vector<vector<char> > & maze, vector<vector<int> > & visited, int x, int y){
    int n=maze.size();
    if(x==n-1 && y==n-1) return true;
    if(x>=n || x<0 || y>=n || y<0 ) return false;
    if(maze[x][y] == 'B' || visited[x][y] != 0) return false;
    visited[x][y] = 1;
    bool has_path = false;
    has_path = dfs(maze, visited, x+1, y)||
        dfs(maze, visited, x-1, y) ||
        dfs(maze, visited, x, y+1) ||
        dfs(maze, visited, x, y-1);
    visited[x][y] = 0;
    return has_path;
}

bool hasPath(vector<vector<char> >& maze){
    if(maze.empty()) return false;
    int n = maze.size();
    std::vector<vector<int> > visited(n, vector<int>(n, 0));
    return dfs(maze, visited, 0, 0);
}

TEST(test_case, I){
    vector<string> maze_{
            "##BB##",
            "#B####",
            "####B#",
            "#BBB##",
            "B###B#",
            "B#B###"
            };
    vector<vector<char> > maze;
    for(auto it=maze_.begin(); it!=maze_.end();++it){
        vector<char> row;
        std::copy(it->begin(), it->end(), back_inserter(row));
        maze.push_back(row);
    }
    print2DVector(maze);
    bool res = true;
    ASSERT_EQ(res, hasPath(maze));
}

TEST(test_case, II){
    vector<string> maze_{
            "##BB##",
            "#B####",
            "####B#",
            "#BBB##",
            "B###BB",
            "B#B###"
            };
    vector<vector<char> > maze;
    for(auto it=maze_.begin(); it!=maze_.end();++it){
        vector<char> row;
        std::copy(it->begin(), it->end(), back_inserter(row));
        maze.push_back(row);
    }
    print2DVector(maze);
    bool res = false;
    ASSERT_EQ(res, hasPath(maze));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}