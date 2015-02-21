#include <gtest/gtest.h>
#include "utils.h"

using namespace std;
/*
  idea:
  1. like refer best time buy sell stock III, use DP : local and global max
  global[i] the maximum subarray ending at pos i
  local[i] : the max number can be reached at pos i
  local[i] = max(A[i], local[i-1]+A[i])
  global[i] = max(global[i-1], local[i])
  O(n) time
  2. divide and conquer
  O(nlogn)
 */ 
int maxSubArray(int A[], int n){
    if (n==0 || A==nullptr) return 0;
    vector<int> local(n, 0);
    vector<int> global(n, 0);
    local[0] =  A[0];
    global[0] = A[0];
    for(int i=1; i<n; i++){
        local[i] = max(A[i], local[i-1] + A[i]);
        global[i] = max(global[i-1], local[i]);
    }
    return global[n-1];
}

TEST(MaxSubArray, I){
    int A[] ={-2,1,-3,4,-1,2,1,-5,4};
    int res = 6;
    ASSERT_EQ(res, maxSubArray(A, 9));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


