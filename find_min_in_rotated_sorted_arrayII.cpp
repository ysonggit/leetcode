#include "utils.h"
#include <gtest/gtest.h>
using namespace std;
/*
  binary search
  if num[front] >= num[back]
     then mini element locates in between
  if two elements in two halves are equal, search two sides in order
 */

// question: if null array, return ?
int findMin(vector<int> &num) {
    if(num.size()==0) return 0;
    int front = 0;
    int back = num.size() - 1;
    int cur_min = num[0];
    while(front < back){
        int mid = (front + back)/2;
        if(num[mid] > num[back]){
            // min is in the right half
            cur_min = min(cur_min, num[back]);
            front = mid+1;
        }
        else if(num[mid] < num[back]){
            cur_min = min(cur_min, num[mid]);
            back = mid-1;
        }else{
            back--;
        }
    }
    return min(cur_min, min(num[front], num[back]));
}

TEST(FindMin, One){
    vector<int> num{3,1,2,3,3,3,3};
    int res = 1;
    ASSERT_EQ(res, findMin(num));
}

TEST(FindMin, Two){
    vector<int> num{3,3,3,3,3,1,2};
    int res = 1;
    ASSERT_EQ(res, findMin(num));
}

TEST(FindMin, Three){
    vector<int> num{1,2,3,3,4,5,6,6};
    int res = 1;
    ASSERT_EQ(res, findMin(num));
}

TEST(FindMin, Four){
    vector<int> num{3,1,1};
    int res = 1;
    ASSERT_EQ(res, findMin(num));
}

TEST(FindMin, Five){
    vector<int> num{4,5,6,7,0,1,2};
    int res = 0;
    ASSERT_EQ(res, findMin(num));
}

int main(int argc, char *argv[]){    
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

