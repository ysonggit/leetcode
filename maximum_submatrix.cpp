#include <gtest/gtest.h>
#include "utils.h"
using namespace std;
/*
  given an N x N matrix of positive and negative integers, find the submatrix
  with the maximum sum
  source : cc150

  idea:
  similar to maximum sum subarray,
  for each row_start and for each row end, sum up the value of entire column
  for example,
    1  8 0  3   ---- starting row
    7 -5 -4 2   ---- ending row
 can be treated as
     8 3 -4 5
  
 */
long maxSubarray(vector<int> array){
    int n=array.size();
    if(n==0) return 0;
    long local_max = array[0];
    long global_max = array[0];
    for(int i=1; i<n; i++){
        int cur = array[i];
        local_max = max(local_max+cur, (long) cur);
        global_max = max(local_max, global_max);
    }
    return global_max;
}

long maxSubmatrix(vector<vector<int> > matrix){
    int n = matrix.size();
    if(n==0) return 0;
    long max_sum = LONG_MIN;
    for(int i=0; i<n; i++){ // starting row index
        for(int j=n-1; j>=0; j--){ // ending row index
            // search between starting row and ending row
            vector<int> array(n, 0);
            for(int col=0; col<n; col++){
                for(int k=i; k<=j; k++){
                    array[col] += matrix[k][col];
                }
            }
            max_sum = max(max_sum, maxSubarray(array));
        }
    }
    return max_sum;
}

TEST(SubMatrix, I){
    vector<vector<int> > matrix ={
        {9,-8,1, 3, -2},
        {-3,7,6,-2,4},
        {6,-4,-4,8,-7},
        {12,-5,3, 9, -5}
    };
    int res = 38;
    ASSERT_EQ(res, maxSubmatrix(matrix));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}