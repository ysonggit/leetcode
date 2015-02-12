#include "utils.h"
#include <gtest/gtest.h>

using namespace std;

/*
  idea
  take sign
  reverse bit by bit from right to left
  check overflow in advance

  x = 12340
  res = 0
  1. 
  res = res * 10 +  x % 10  --> 0
  x /= 10    --> 1234
  2. 
  res = res * 10 +  x % 10 --> 4
  x /= 10    --> 123
  3.
  res = res * 10 + x % 10 --> 43
  x /= 10   --> 12
  4.
  res = res * 10 + x % 10  --> 432
  x /= 10   --> 1
  5.
  res = res * 10 + x % 10 --> 4321
  x /10 = 0
  4321
 */
int reverse(int x){
    int sign = 1;
    if (x < 0) sign = -1;
    // reverse abs(x)
    int res = 0;
    x = abs(x);
    while(x>0){
        // predict overflow
        if(res > INT_MAX/10 || (res == INT_MAX/10 && (x % 10) > (INT_MAX%10))) {
            return 0;
        }
        res = res * 10 + x % 10;
        x /= 10;
    }
    return sign * res;
}

TEST(REVERSE, I){
    int x = 1234560;
    int res = 654321;
    ASSERT_EQ(res, reverse(x));
}

TEST(REVERSE, II){
    int x = 2147483647;
    int res = 0;
    ASSERT_EQ(res, reverse(x));
}

TEST(REVERSE, III){
    int x = -123;
    int res = -321;
    ASSERT_EQ(res, reverse(x));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}




