#include "utils.h"
#include <gtest/gtest.h>

using namespace std;
/*
  idea : divide and conquer
  max_profit[0..n-1] = max_profit[0,i] + max_profit[i+1,n-1] 
  use array left[] to store the max_profit obtained before day i
  use array right[] to store the max_profit obtained after day i
 */
int maxProfit(vector<int> &prices) {
    int n = prices.size();
    if(n<=1) return 0;
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    // min_val saves the minimal buying price before day i
    int min_val = prices[0];
    for(int i=1; i<n; i++){
        left[i] = max(prices[i] - min_val, left[i-1]);
        min_val = min(prices[i], min_val);
    }
    // max_val means the maximal selling price after day i
    // search from end to front
    int max_val = prices[n-1];
    for(int i=n-2; i>=0; i--){
        right[i] = max(max_val -prices[i], right[i+1]);
        max_val = max(prices[i], max_val);
    }
    // locate the max_profit
    // printVector(left);
    // printVector(right);
    int max_profit = left[n-1];
    for(int i=0; i<n-1; i++){
        max_profit= max(max_profit, left[i]+right[i+1]);
    }
    return max_profit;
}

TEST(StockIII, I){
    vector<int> prices={6,1,3,2,4,7};
    int res = 7;
    ASSERT_EQ(res, maxProfit(prices));
}


TEST(StockIII, II){
    vector<int> prices={1,2};
    int res = 1;
    ASSERT_EQ(res, maxProfit(prices));
}

TEST(StockIII, III){
    vector<int> prices={3,2,1};
    int res = 0;
    ASSERT_EQ(res, maxProfit(prices));
}

TEST(StockIII, IV){
    vector<int> prices={3,2,6,5,0,3};
    int res = 7;
    ASSERT_EQ(res, maxProfit(prices));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


