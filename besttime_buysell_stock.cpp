#include "utils.h"

using namespace std;

int maxProfit(vector<int> &prices) {
    if(prices.size()<=1) return 0;
    int max_profit = 0;
    int min_val = prices[0];
    for(int i=1; i<prices.size(); i++){
        max_profit = max(max_profit, prices[i]-min_val);
        min_val = min(min_val, prices[i]);
    }
    return max_profit;
}

int main(){
    vector<int> prices = {3,2,1,3,5,6,9,4}; // should be 8
    cout<<maxProfit(prices)<<endl;
    return 0;
}
