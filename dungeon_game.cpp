#include "utils.h"

using namespace std;

/*
  idea : DP
         define min_hp(i, j) as the minimum health point to reach grid G(i,j)
         min_hp(i,j) = min(min_hp(i+1,j), min_hp(i,j+1)) - cost(i,j) if cost(i,j) <=0 OR
                                                                     if cost(i,j) >0 && cost(i,j) < min(min_hp(i+1,j), min_hp(i, j+1)) 
                     =  1                                            if cost(i,j) >0 && cost(i,j) > min(min_hp(i+1,j), min_hp(i, j+1))
*/

int calculateMinimumHP(vector<vector<int> > &dungeon) {
    const int m = dungeon.size();
    if(m<0) return 0;
    const int n = dungeon[0].size();
    //vector<vector<int> > min_hp(m+1, vector<int>(n+1, 0));
    int min_hp[m+1][n+1];
    for(int i=0; i<m+1; i++){
        min_hp[i][n] = INT_MAX;
    }
    for(int i=0; i<n+1; i++){
        min_hp[m][i] = INT_MAX;
    }
    min_hp[m][n-1] = 1;
    for(int i=m-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            min_hp[i][j] =  min(min_hp[i][j+1], min_hp[i+1][j]);
            if(dungeon[i][j]<=0 || (min_hp[i][j] > dungeon[i][j]) ){
                min_hp[i][j] -= dungeon[i][j];
            }else{
                min_hp[i][j] = 1;
            }
        }
    }
    return min_hp[0][0];
}

int main(int argc, char *argv[])
{
    vector<vector<int> > dungeon{
        {-2,-3,3},
        {-5,-10,1},
        {10,30,-5}
    };
    cout<<calculateMinimumHP(dungeon)<<endl;
    return 0;
}


