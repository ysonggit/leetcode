#include "utils.h"

using namespace std;

/*
  greedy search for increasing sequence:
  if prices[i] > prices[i-1] , profit += prices_diff
    
 */
int maxProfit(vector<int> &prices) {
    int n = prices.size();
    int profit = 0;
    if(n==0) return profit;
    for(int i=0; i<n-1; i++){
        if(prices[i+1]>prices[i]){
            profit += prices[i+1] - prices[i];
        }
    }
    return profit;
}

int main(){
    int A[] = {
        5,1,2,3,4,0
    };
    vector<int> prices(A, A+sizeof(A)/sizeof(int));
    cout<<maxProfit(prices)<<endl;

    return 0;
}
