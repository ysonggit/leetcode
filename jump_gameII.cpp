#include "utils.h"
#include <gtest/gtest.h>

using namespace std;

/*
  question : guaranteed to reach the last index?
             how about unreachable case?

  idea: (refer linhuanmars csdn blog)
         max_reachable_idx = A[i] + i is the furthest idx reachable from current pos
         instead of tracking a global_max_idx = max(local_max_idx, global_max_idx) (Jump game I)
         here maintains a idx_reachable_min_steps
         if current pos is > the idx_reachable_min_steps
              idx_reachable_min_steps += 1
*/

int jump(int A[], int n){
    if(n<=0) return 0;
    int max_reachable_idx = 0, idx_reachable_min_steps = 0, min_steps=0;
    for(int i=0; i<n; i++){
        if(i > idx_reachable_min_steps){
            min_steps++;
            idx_reachable_min_steps = max_reachable_idx;
        }
        max_reachable_idx = max(A[i]+i, max_reachable_idx);
    }
    return min_steps;
}

TEST(Jump, One){
    int A[] ={2,3,1,1,4};
    int n=5;
    int res = 2;
    ASSERT_EQ(res, jump(A, n));
}

TEST(Jump, Two){
    int A[] ={2,1};
    int n=2;
    int res = 1;
    ASSERT_EQ(res, jump(A, n));
}

TEST(Jump, Three){
    int A[] ={1};
    int n=1;
    int res = 0;
    ASSERT_EQ(res, jump(A, n));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


