#include "utils.h"
#include <gtest/gtest.h>

using namespace std;
/*
  idea : can not find n! then count on zeroes because of overflow
  # of trailing zeroes = # of 5 and 2 pairs
  = # of 5s in prime factors of n!

  For a prime factor p of n, the multiplicity of p is
  the largest exponent a for which p^a divides n exactly.
  for example : n=20
  20! =  2432902008176640000 which has 4 trailing zeroes.
  =  20 x 19 x .. 15 x .. x 10 x ... x 5 x ...2 x 1
  =  2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*3*3*3*3*3*3*3*3*5*5*5*5*7*7*11*13*17*19
*/

int trailingZeroes(int n) {
    int count = 0;
    for(unsigned long long i=5; i<= n; i *= 5){// trick: i *=5 may  overflow if input int is INT_MAX
        count += n/i;
    }
    return count;
}

TEST(Five, One){
    ASSERT_EQ(1, trailingZeroes(5));
}

TEST(Twenty, Four){
    ASSERT_EQ(4, trailingZeroes(20));
}

TEST(Hundred, TwentyFour){
    ASSERT_EQ(24, trailingZeroes(100));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

