#include "utils.h"
#include <gtest/gtest.h>
using namespace std;

bool search(int A[], int n, int target) {
    if(n<=0) return false;
    int front = 0, back=n-1;
    while(front<=back){
        int mid=(front+back)/2;
        if(A[mid]==target){
            return true;
        }
        if(A[mid] > A[back] ){
            // the array is for sure rotated & the min element is in the right half, see 3,4,5,1,2
            // determine target  0,0,1,1,2,0
            if(A[front] <= target && A[mid] > target){
                // target is for sure in the left half
                back = mid-1;
            }else{
                // search right half
                front = mid+1;
            }
        }
        else if(A[mid] < A[back]){
            // the mini element could be in middle, 4,5,1,2,3, or in left half 5,1,2,3,4
            if(A[mid] < target && A[back] >= target){
                // target is for sure in the right half
                front = mid+1;
            }else{
                back = mid-1;
            }
        }else{
            // A[mid] == A[back] means duplicates : can not tell which half to go: 4,1,2,3,3,3,3
            back--;
        }
    }
    return false;
}

TEST(Search, One){
    int A[] = {4,1,2,3,3,3,3};
    int res = true;
    ASSERT_EQ(res, search(A, 7, 1));
}

TEST(Search, Two){
    int A[] = {0,0,1,1,2,0};
    int res = true;
    ASSERT_EQ(res, search(A, 6, 2));
}


TEST(Search, Three){
    int A[] = {4,5,0,1,2,3,3};
    int res = true;
    ASSERT_EQ(res, search(A, 7, 3));
}

TEST(Search, Four){
    int A[] = {3,5,1};
    int res = true;
    ASSERT_EQ(res, search(A, 3, 1));
}


int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


