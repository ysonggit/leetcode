/*
   House1   House2   House3  
R   10        3        4
G   1         0        7
B   2         8        1
house1 10
house2  0,     8
        4, 1   4,7
Return the minimum cost of painting all the houses, no two neighboring houses are painted in same color. Assuming there are m color and n houses.
*/
// brute-force: find all possible combinations
// row is color
// col is house id
// {{10, 0, 4}  {10, 0, 1}, ... }
#include <gtest/gtest.h>
#include "utils.h"
using namespace std;

void dfs(vector<vector<int> > & prices, vector<int>& costs, vector<int> & sol, int cur_house_idx, int pre_house_color_idx){
    if(cur_house_idx == prices[0].size()){
        int price_sum = accumulate(sol.begin(), sol.end(), 0);
        //for_each(sol.begin(), sol.end(), [](int & j) {cout<<j<<", ";});
        //cout<<endl;
        costs.push_back(price_sum);
        return ;
    }
    for(int i= 0; i<prices.size(); i++){
        if(pre_house_color_idx !=i){
            sol.push_back(prices[i][cur_house_idx]);
            dfs(prices, costs, sol, cur_house_idx+1,i);
            sol.pop_back();
        }
    }
}

int minCost(vector<vector<int> > & prices){
    if(prices.size()==0) return 0;
    //int price_sum=0;
    vector<int> costs;
    vector<int> sol;
    dfs(prices, costs, sol, 0, -1);
    return *min_element(costs.begin(), costs.end());
}
    

TEST(MinCost, I){
    vector<vector<int> > prices = {
        {10, 3, 4},
        {1,  0, 7},
        {2,  8, 1}
    };
    int res = 3;
    ASSERT_EQ(res, minCost(prices));
}

TEST(MinCost, II){
    vector<vector<int> > prices = {
        {0, 1},
        {3, 2},
        {2, 4}
    };
    int res = 2;
    ASSERT_EQ(res, minCost(prices));
}

/*
    House1   House2   House3  House4  House5
R   4        3        4       5       7
G   1        5        7       3       4
B   2        9        2       6       1
W   3        4        5       2       6

*/
TEST(MinCost, III){
    vector<vector<int> > prices = {
        {4, 3, 4, 5, 7},
        {1, 5, 7, 3, 4},
        {2, 9, 2, 6, 1},
        {3, 4, 5, 2, 6}
    };
    int res = 9;
    ASSERT_EQ(res, minCost(prices));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

