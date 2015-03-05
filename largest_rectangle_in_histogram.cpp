#include "utils.h"
#include <gtest/gtest.h>

using namespace std;

/*
   maintains a variable max_rect
   use stack s
   s.push(H[0])
   for each height H[i] i = 1...n-1
       if(H[i]<H[s.top])
          s.pop
          compute popped area and update max_rect (...)
      push i

      http://blog.csdn.net/linhuanmars/article/details/20524507

6|      _
5|    _| |
4|   | | |
3|   | | |  _
2|_  | | |_| |
1| |_| | | | |
0|_|_|_|_|_|_|___
key: how to trace the max_area composed by current bar and popped bars?

max_area = max(max_area, 
               popped_height * cur_idx-top_idx_left_instack -1 || 
               popped_height * cur_idx_if_stack_is_empty) // when all saved heights are popped out
max_area = 0

i=0 stack push i
    stack: 0, 
i=1 A[1] < A[stack.top]
    pop, max_area = max(0,  A[0]*1) = 2
    push i to stack,
    stack: 1 
i=2 A[2]=5, push i 
    stack: 2,1 
i=3 A[3]=6, push i 
    stack: 3,2,1 
i=4 A[4]=2, 
    pop  max_area = max(2,  A[3]*(4-2-1)) = 6
    stack: 2,1
    pop  max_area = max(6, A[2]*(4-1-1)) = 10
    stack: 1    
i=5 A[5]=3, push i
    stack: 3,1
    
    calculate the area remaining in the stack
*/
int largestRectangleArea(vector<int> &height) {
    if(height.empty()) return 0;
    int max_area = 0;
    stack<int> highest_bars_left;
    height.push_back(0); // make sure finally the stack will be empty
    int n = height.size();
    for(int idx=0; idx<n; idx++){
        while(!highest_bars_left.empty() && 
            height[idx] < height[highest_bars_left.top()]){
            int highest_idx = highest_bars_left.top();
            highest_bars_left.pop();
            // update max_area
            int width = highest_bars_left.empty() ? idx : (idx-highest_bars_left.top()-1);
            max_area = max(max_area, width * height[highest_idx]);
        }
        highest_bars_left.push(idx);
    }
    return max_area;
}

TEST(LargestRectangle, One){
    vector<int> height = {2,1,5,6,2,3};
    int res = 10;
    ASSERT_EQ(res, largestRectangleArea(height));
}

TEST(LargestRectangle, Two){
    vector<int> height = {1,1};
    int res = 2;
    ASSERT_EQ(res, largestRectangleArea(height));
}

TEST(LargestRectangle, Three){
    vector<int> height = {1};
    int res = 1;
    ASSERT_EQ(res, largestRectangleArea(height));
}

TEST(LargestRectangle, Four){
    vector<int> height = {2,0,2};
    int res = 2;
    ASSERT_EQ(res, largestRectangleArea(height));
}

TEST(LargestRectangle, Five){
    vector<int> height = {4,2};
    int res = 4;
    ASSERT_EQ(res, largestRectangleArea(height));
}

TEST(LargestRectangle, Six){
    vector<int> height = {2,1,2};
    int res = 3;
    ASSERT_EQ(res, largestRectangleArea(height));
}

TEST(LargestRectangle, Seven){
    vector<int> height = {0,0,0,1,2,3,0,0,9};
    int res = 9;
    ASSERT_EQ(res, largestRectangleArea(height));
}

TEST(LargestRectangle, Eight){
    vector<int> height = {1,2,1};
    int res = 3;
    ASSERT_EQ(res, largestRectangleArea(height));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


