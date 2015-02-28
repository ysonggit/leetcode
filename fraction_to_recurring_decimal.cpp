#include <gtest/gtest.h>
#include "utils.h"

using namespace std;
/*
  idea:
  example:
  1/6 = 0.1(6)

    0.16
   _____
6 ) 1.00
    0
    ____
    1 0       <-- Remainder=1, mark 1 as seen at position=0.
    - 6
    ____
      40      <-- Remainder=4, mark 4 as seen at position=1.
    - 36
    ____
       4      <-- Remainder=4 was seen before at position=1, so the fractional part which is 16 starts repeating at position=1 => 1(6).

   remainder = 1%6 
       
   question : if denominator is 0 return ?
   deal with overflow
*/

string fractionToDecimal(int numerator, int denominator) {
    if(numerator==0) return string("0");
    if(denominator==0) return string("NAN");
    int sign = ( (numerator ^ denominator)>=0 ) ? 1 : -1;
    string res;
    if(sign<0) res += string("-");
    // trick : convert to positive and use long to avoid overflow
    // for example, numberator is INT_MIN, abs(INT_MIN)> INT_MAX
    // tricky: MUST cast numerator to long then find absolute value
    // http://blog.csdn.net/ljiabin/article/details/42025037
    // long num = abs(numerator) would work for overflow:
    // if numerator is INT_MIN, then
    // long num = Math.abs(-2147483648) still returns INT_MIN
    long num = abs((long)numerator), den = abs((long)denominator);
    long int_part  = (long) num/den;
    stringstream ss;
    ss<<int_part;
    res += ss.str();
    //Overflow can occur during a modulo operation when the dividend is equal to the minimum (negative) value for the signed integer type and the divisor is equal to -1
    long remainder = num % den;
    if(remainder==0) return res;
    res += string(".");
    // if have remainder
    // key is remainder, value is the length of the converted string so far
    // for example, 1/6  remainder 4 correspondes to the number 6
    map<long, int> remainders;
    while(remainder != 0){
        if(remainders.find(remainder)!= remainders.end()){
            int len_before_recur = remainders[remainder];
            string part1 = res.substr(0, len_before_recur);
            string part2 = res.substr(len_before_recur);
            return part1+string("(")+part2+string(")");
        }
        long num_remainder =  (remainder * 10)/den;
        //cout<<remainder<<" "<<num_remainder<<endl;
        remainders[remainder] = res.length();
        stringstream s;
        s<<num_remainder;
        res += s.str();
        remainder = (remainder * 10)%den;
    }
    return res;
}

TEST(Fraction, I){
    const char * res = "0.1(6)";
    int numerator = 1;
    int denominator = 6;
    ASSERT_STREQ(res, fractionToDecimal(numerator, denominator).c_str());
}

TEST(Fraction, II){
    const char * res = "0.5";
    int numerator = 1;
    int denominator = 2;
    ASSERT_STREQ(res, fractionToDecimal(numerator, denominator).c_str());
}

TEST(Fraction, III){
    const char * res = "2";
    int numerator = 2;
    int denominator = 1;
    ASSERT_STREQ(res, fractionToDecimal(numerator, denominator).c_str());
}

TEST(Fraction, IV){
    const char * res = "-0.(6)";
    int numerator = -2;
    int denominator = 3;
    ASSERT_STREQ(res, fractionToDecimal(numerator, denominator).c_str());
}

TEST(Fraction, V){
    const char * res = "0.(01)";
    int numerator = 1;
    int denominator = 99;
    ASSERT_STREQ(res, fractionToDecimal(numerator, denominator).c_str());
}


TEST(Fraction, VI){
    const char * res = "0.0000000004656612873077392578125";
    int numerator = -1;
    int denominator = -2147483648;
    ASSERT_STREQ(res, fractionToDecimal(numerator, denominator).c_str());
}

TEST(Fraction, VII){
    const char * res = "-2147483648";
    int numerator = -2147483648;
    int denominator = 1;
    ASSERT_STREQ(res, fractionToDecimal(numerator, denominator).c_str());
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



