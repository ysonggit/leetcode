#include "utils.h"
#include <gtest/gtest.h>

using namespace std;

/*
  idea: buysell stock II & III
  if k is far greater than prices.size, then it is actually the buysell stock II problem
  so create an array to save all positive diff of prices[i] and prices[i-1]
  the max profit is the sum

  otherwise DP
  https://gist.github.com/ElninoFong/d08051d98e634991cd93
  local_max_profit [i][j] is the max proft obtained from the last transaction at day i, after j transactions totally
  global_max_profit [i][j] is the max profit obtained at day i after j transctions

  example prices ={2,1,2,0,1}
  local_max_profit[5][2] = 1
  global_max_profit [5][2] = 2

  local[i][j] = max(global[i-1][j-1]+max(0, diff), local[i-1][j]+diff)
  global[i][j] = max(local[i][j], global[i-1][j])
 */
int getMaxProfit(vector<int> & prices){
    if(prices.size()<=1) return 0;
    int max_profit = 0;
    for(int i=1; i<prices.size(); i++){
        if(prices[i]>prices[i-1]) {
            max_profit += prices[i] - prices[i-1];
        }
    }
    return max_profit;
}

int maxProfit(int k, vector<int> &prices) {
    int n = prices.size();
    if(k<=0 || n<=1) return 0;
    if(k>= n) return getMaxProfit(prices);
    vector<vector<int> > local(n, vector<int>(k+1, 0));
    vector<vector<int> > global(local);
    for(int i=1; i<n; i++){
        int diff = prices[i] - prices[i-1];
        for(int j=1; j<=k; j++){
            local[i][j] = max(global[i-1][j-1]+max(0, diff),
                local[i-1][j] + diff );
            global[i][j] = max(local[i][j], global[i-1][j]);
        }
    }
 
    return global[n-1][k];
}

TEST(MaxProfit, I){
    vector<int> prices ={3,3,5,0,0,3,1,4};
    int k = 2;
    int res = 6;
    ASSERT_EQ(res, maxProfit(k, prices));
}

TEST(MaxProfit, II){
    vector<int> prices ={3,2,6,5,0,3};
    int k = 2;
    int res = 7;
    ASSERT_EQ(res, maxProfit(k, prices));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

