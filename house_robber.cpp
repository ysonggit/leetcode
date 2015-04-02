#include <gtest/gtest.h>
#include "utils.h"
using namespace std;
/*
  idea:
  DP
  D[i] the max money by robbering from first i houses
  D[i] = max of D[i-1]         // do not rob current
                D[i-2] + cur   // rob current house
 */
int rob(vector<int> &num) {
    int n = num.size();
    if(n<1) return 0;
    vector<int> D(n+1, 0);
    D[1] = num[0];
    for(int i=2; i<=n; i++){
        D[i]= max(D[i-2]+num[i-1], D[i-1]);
    }
    return D[n];
}

TEST(ROB, I){
    vector<int> num{1,2,3,4,5,6,7};
    int res = 16;
    ASSERT_EQ(res, rob(num));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
