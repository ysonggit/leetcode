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
*/

int largestRectangleArea(vector<int> &height) {
    if(height.size()==0) return 0;
    stack<int> s;
    int n= height.size();
    int max_rect = 0; 
    int cur_height = 0;
    int max_area_popped = 0;
    for(int i=0; i< n; i++){
        cur_height =  height[i];
        while(!s.empty() && cur_height <= height[s.top()] ){
            int cur_idx = s.top();
            s.pop();
            int max_area_popped = s.empty() ? i * height[cur_idx] :  (i-s.top()-1)*height[cur_idx];
            max_rect = max(max_rect, max_area_popped);
        }
        s.push(i);
    }
    // so far, a special case is not considered think of 2,1,2 or 1, 1
    // the first bar actually contributes to the max rectangle with area 3
    while(!s.empty() ){
        int cur_idx = s.top();
        s.pop();
        int cur_area = s.empty() ? n* height[cur_idx] :  (n-s.top()-1)*height[cur_idx];
        max_rect = max(max_rect, cur_area);
     }
       
    return max_rect; 
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
    vector<int> height = {2,4};
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


