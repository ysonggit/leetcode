#include <gtest/gtest.h>
#include "utils.h"

using namespace std;

/*
  idea:
  bit shift
  given a number n, it can be represented as linear combinations
  n = a_0 * 2^0 + a_1 * 2 + a_2 * s^2 + ... a_m * 2^m

  shift the divisor to left until it become the largest number less than the dividend
  for example, 120/14
  res = 0
  0) 14<<0  -> 14,  res += 1<<0  1, dividend -= 14 => 106
  1) 14<<1  -> 28,  res += 1<<1  3, dividend -= 28 => 78
  2) 28<<1  -> 56,  res += 1<<2  7, dividend -= 56 => 22

  0) 14<<0 ->14,  res += 1<<0 8, dividend -= 14 = 8 < dividor

  overflow: use long long
*/

int divide(int dividend, int divisor) {
    if(divisor==0) return INT_MAX;
    // if (a^b)>=0 , then a and b have the same sign
    int sign = ((dividend ^ divisor)>=0) ? 1 : -1;
    // long long 2^63 
    long long dividend_ll = abs((long long)dividend);
    long long divisor_ll = abs((long long)divisor);
    long long res_ll = 0;
    while(dividend_ll >=divisor_ll ){
        long long divisor_shift_ll = divisor_ll;
        for(int i=0; (divisor_shift_ll<<i) <= dividend_ll; i++){
            dividend_ll -= divisor_shift_ll<<i;
            res_ll += (1<<i);
        }
    }
    // note , long long could represent a number greater than INT_MAX
    if(sign<0) res_ll = - res_ll;
    // above if statement is necessary
    // otherwise, when res_ll = 2147483648, and sign is -1
    // it will return 2147483647 but not -2147483648
    if(res_ll > INT_MAX) return INT_MAX;
    return res_ll;
}

TEST(Divide, I){
    int dividend = 120;
    int divisor = 14;
    int res = 8;
    ASSERT_EQ(res, divide(dividend, divisor));
}

TEST(Divide, II){
    int dividend = 1;
    int divisor = 1;
    int res = 1;
    ASSERT_EQ(res, divide(dividend, divisor));
}

TEST(Divide, III){
    int dividend = -2147483648;
    int divisor = 1;
    int res = -2147483648;
    ASSERT_EQ(res, divide(dividend, divisor));
}

TEST(Divide, IV){
    int dividend = -2147483648;
    int divisor = -1;
    int res = 2147483647;//INT_MAX
    ASSERT_EQ(res, divide(dividend, divisor));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



