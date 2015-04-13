#include <gtest/gtest.h>
#include "utils.h"
using namespace std;
/*
  Input: [0, 1, 0, 0, 4, 2, 0, 3]
  Output: [1, 4, 2, 3, 0, 0, 0, 0]
  Requirements: 1) shift nonzero elements to the front of the array
                2) maintain the ordering of the nonzero elements

  Source: facebook

  idea : similar to the remove duplicates from sorted array
 */
void moveZerosToRight(vector<int> & nums){
    int n = nums.size();
    if(n==0) return;
    int j= 0;
    for(int i=0; i<n; i++){
        if(nums[i]!=0){
            nums[j] = nums[i];
            j++;
        }
    }
    // append 0s to the right
    while(j<n){
        nums[j]=0;
        j++;
    }
}

TEST(MoveZeros, I){
    vector<int> nums{0,1,0,0,4,2,0,3};
    printVector(nums);
    moveZerosToRight(nums);
    printVector(nums);    
}

TEST(MoveZeros, II){
    vector<int> nums{0,0,0,0};
    printVector(nums);
    moveZerosToRight(nums);
    printVector(nums);    
}

TEST(MoveZeros, III){
    vector<int> nums{0,0,0,0,4,2,0,0};
    printVector(nums);
    moveZerosToRight(nums);
    printVector(nums);    
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

