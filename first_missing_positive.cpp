#include "utils.h"
#include <gtest/gtest.h>
using namespace std;

/*
  bucket sort: use the element itself as its position  in the array
  that is, ideally, we want:
  A[i] = i+1 for each i = 0 ... n-1
  in another word, we have i=A[i]-1 such that A[i] = A[A[i]-1]
  if any A[i] != i+1, then that is the positive number missing

  for i = 0 ... n-1
      if A[i] != A[A[i]-1] && A[i] > 0
          swap(A[i] and A[A[i]-1])

  [3, 4, -1, 1] do bucket sort:
  i = 0,  A[0] != A[A[0]-1]  --  [-1, 4, 3, 1]  (swap A[2] and A[0])
            3        -1
                                 break;
  i = 1,  A[1] != A[A[1]-1]  --  [-1, 1, 3, 4]
            4        1
                                 A[1] != A[A[1]-1]  -- [1, -1, 3, 4]
                                   1       -1
  i = 2,  A[2] == A[A[2]-1]
            3        3
  i = 3,  A[3] == A[A[3]-1]
            4        4
  now search sorted array
  if A[i]!= i+1 
     return i+1

  otherwise, return n+1
*/

int firstMissingPositive(int A[], int n) {
    for( int i=0; i<n ; i++){
        // idea: index of A is bounded [0, n-1]
        // value of sorted A is bounded [1, n]
        while(A[i] != i+1){
            if(A[i] <=0 || A[i] > n || A[i] == A[A[i]-1] || A[i]-1 >=n || A[i]-1<0) break;
            int temp = A[i];
            A[i] = A[A[i]-1];
            A[temp-1] = temp;// tricky: can not do A[A[i]-1] = temp, since A[i] is already changed
        }
    }
    for(int i=0; i<n; i++){
        if(A[i] != i+1){
            return i+1;
        }
    }
    return n+1; //tricky : if A[]={}, should return 1
}

TEST(Case, One){
    int A[3] = {1,2,0};
    int res = 3;
    ASSERT_EQ(res, firstMissingPositive(A, 3));
}

TEST(Case, Two){
    int A[4] = {3,4,-1,1};
    int res = 2;
    ASSERT_EQ(res, firstMissingPositive(A, 4));
}

TEST(Case, Three){
    int A[4] = {13, 11, 10, 8};
    int res = 1;
    ASSERT_EQ(res, firstMissingPositive(A, 4));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
