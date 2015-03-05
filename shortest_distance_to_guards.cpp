#include <gtest/gtest.h>
#include "utils.h"
using namespace std;
/*
  
  given a map of a garden,  represented as a 2D m-by-n matrix
  _ represents a free spot,
  G represents a guard,
  B represents a block
  _____________
  |_|G|_|_|B|_|
  |B|_|_|_|_|_|
  |_|_|_|_|G|_|
  |_|B|_|_|_|_|
  |G|_|_|_|_|_|
  
   write a function to fill the map
   so that each free spot has the shortest distance to a guard
   for each spot where there is a guard, fill 0
   for the spots where are blocks, fill -1
  _____________
  |1|0|1|2|-1|3|
  |-1|1|2|2|1|2|
  |2|2|2|1|0|1|
  |1|-1|3|2|1|2|
  |0|1|2|3|2|3|

  idea :
  from each guard, do BFS
  first find all guards and push them to a queue
  use a set to track visited spot
*/

typedef pair<int, int> Pos;

vector<vector<int> > fillMap(vector<vector<char> >& garden){
    if(garden.empty()) return vector<vector<int> >();
    queue<Pos> Q;
    int m = garden.size();
    int n = garden[0].size();
    vector<vector<int> > visited(m, vector<int>(n, 0));
    vector<vector<int> > res(visited);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(garden[i][j]=='G'){
                Pos guard_pos = make_pair(i,j);
                Q.push(guard_pos);
                visited[i][j] = 1;
            }
            if(garden[i][j]=='B'){
                res[i][j] = -1;
            }
        }
    }
    //print2DVector(res);
    int distance = 1;
    while(!Q.empty()){
        int num_cur_level = Q.size();
        for(int i=0; i<num_cur_level; i++){
            Pos cur_spot = Q.front();
            Q.pop();
            int x = cur_spot.first;
            int y = cur_spot.second;
            if(x>0 && visited[x-1][y]==0 && garden[x-1][y] == '_'){
                res[x-1][y] = distance;
                Q.push(make_pair(x-1, y));
                visited[x-1][y] = 1;
            }
            if(x<m-1 && visited[x+1][y]==0 && garden[x+1][y]=='_'){
                res[x+1][y] = distance;
                Q.push(make_pair(x+1, y));
                visited[x+1][y] = 1;
            }
            if(y>0 && visited[x][y-1]==0 && garden[x][y-1] == '_'){
                res[x][y-1] = distance;
                Q.push(make_pair(x, y-1));
                visited[x][y-1] = 1;
            }
            if(y<n-1 && visited[x][y+1]==0 && garden[x][y+1]=='_'){
                res[x][y+1] = distance;
                Q.push(make_pair(x, y+1));
                visited[x][y+1] = 1;
            }
        }
        distance++;
    }
    return res;
}

TEST(test_case, I){
    vector<string> garden_{
            "_G__B_",
            "B_____",
            "____G_",
            "_B____",
            "G_____",
            };
    vector<vector<char> > garden;
    for(auto it=garden_.begin(); it!=garden_.end();++it){
        vector<char> row;
        std::copy(it->begin(), it->end(), back_inserter(row));
        garden.push_back(row);
    }
    print2DVector(garden);
    vector<vector<int> > res = fillMap(garden);
    print2DVector(res);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
