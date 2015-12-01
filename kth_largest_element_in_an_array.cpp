#include "utils.h"
#include <gtest/gtest.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    if (n==0 || k > n || k< 1) return 0;
    make_heap(nums.begin(), nums.end()); // default is max_heap
    for(int i=0; i<k-1; i++){
        pop_heap(nums.begin(), nums.end());
        nums.pop_back();
    }
    return nums.front();
}   

TEST(KLarge, I){
    vector<int> nums = {3,45,13,2,4,25,9,10,17,31,26,48};
    int k = 5;
    int res = 25;
    ASSERT_EQ(findKthLargest(nums, k), res);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
