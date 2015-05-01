#include <gtest/gtest.h>
#include "utils.h"
using namespace std;
/*
  key: find the common leftmost 1's of m and n
 */
int rangeBitwiseAnd(int m, int n) {
    int count = 0;
    while(m!=n){
        m=m>>1;
        n=n>>1;
        count++;
    }
    return m<<count;
}

TEST(Range, I){
    int m = 0;
    int n = 1;
    int res = 0;
    ASSERT_EQ(res, rangeBitwiseAnd(m, n));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

