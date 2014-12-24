#include "utils.h"
#include <gtest/gtest.h>
using namespace std;

/*
  similar to 2 sum problem
  two pointers : i, j
  area = (j - i) * min(a_i, a_j)
  Greedy search
 */

int maxArea(vector<int> &height) {
    int max_area = 0;
    int i=0;
    int j=height.size()-1;
    while(i<j){
        int a_i = height[i];
        int a_j = height[j];
        int area = (j-i) * min(a_i, a_j);
        if(max_area < area){
            max_area = area;
        }
        if(a_i < a_j){
            i++;
        }else{
            j--;
        }
    }
    return max_area;
}

TEST(Case, One){
    int A[11] = {0, 1, 2, 3, 2, 1, 4, 5, 4, 2, 4};
    int res = 21;
    vector<int> height(A, A+sizeof(A)/sizeof(*A));
    ASSERT_EQ(res, maxArea(height));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

