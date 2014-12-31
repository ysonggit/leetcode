#include "utils.h"

using namespace std;

/*
  # of path to (m, n) = # path to (m-1, n)
                        + # path to (m, n-1)  if G(m,n) = 0

                      = 0  if G(m,n)= 1

  use a m by n grid to record the results
   
*/

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    // base case
    if(obstacleGrid.size()==0 || obstacleGrid[0][0]==1) return 0;
    int rows = obstacleGrid.size();
    int cols = obstacleGrid[0].size();
    int paths[rows][cols];
    int obs_idx_row = -1, obs_idx_col= -1;
    for(int i=0; i<rows; i++){
        if(obstacleGrid[i][0]==1){
            obs_idx_row = i;
            break;
        }
    }
    for(int i=0; i<rows; i++){
        if(obs_idx_row >=0 && i>=obs_idx_row ){
            paths[i][0] = 0;
        }else{
            paths[i][0] = 1;
        }
    }
    for(int i=0; i<cols; i++){
        if(obstacleGrid[0][i]==1){
            obs_idx_col = i;
            break;
        }
    }
    for(int i=0; i<cols; i++){
        if(obs_idx_col >=0 && i>=obs_idx_col ){
            paths[0][i] = 0;
        }else{
            paths[0][i] = 1;
        }
    }    
    for(int i=1; i<rows; i++ ){
        for(int j=1; j<cols; j++){
            if(obstacleGrid[i][j] == 1){
                paths[i][j] = 0;
            }else{
                if(i>=1 && j>=1){
                    paths[i][j] = paths[i-1][j] + paths[i][j-1];
                }
            }
        }
    }
    return paths[rows-1][cols-1];
}


int main(int argc, char *argv[])
{
    vector<vector<int> > grid{
        {0,0},
        {1,1},
        {0,0}
    };
    cout<<uniquePathsWithObstacles(grid)<<endl;
    return 0;
}

