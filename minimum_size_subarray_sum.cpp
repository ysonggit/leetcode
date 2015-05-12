#include <gtest/gtest.h>
#include "utils.h"
using namespace std;

int minSubArrayLen(int s, vector<int>& nums){
    int n = nums.size();
    if(n==0) return 0;
    int max_len = n+1;
    int front=0, back=0;
    int sum=0;
    while(back<n){
        int cur = nums[back];
        if(cur >= s) return 1;
        sum += cur;
        if(sum >= s){
            max_len = min(max_len, back-front+1);
            front++;
            back=front;
            sum=0;
        }else{
            back++;
        }
    }
    return (max_len>n) ? 0 : max_len;
}

TEST(MinSubarray, I){
    vector<int> nums {2,3,1,2,4,3};
    int s = 7;
    int res = 2;
    ASSERT_EQ(res, minSubArrayLen(s, nums));
}

TEST(MinSubarray, II){
    vector<int> nums {2};
    int s = 7;
    int res = 0;
    ASSERT_EQ(res, minSubArrayLen(s, nums));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



