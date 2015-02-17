#include "utils.h"
#include <gtest/gtest.h>
using namespace std;
/*
  idea: simulate add operation using string
  take care of carry out bit
  no need to worry about overflow
  tip: align two numbers first
  11 plus 1
  1. align two numbers 11, 01
  2. add bit from right to left
     0 -> 0 -> 1
   
 */
string addBinary(string a, string b) {
    int a_len = a.length(), b_len = b.length();
    int n = max(a_len, b_len);
    int carry = 0;
    string sum;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(int i=0; i<n; i++){
        int a_i = (i >= a_len) ? 0 : (int) a[i] - '0';
        int b_i = (i >= b_len) ? 0 : (int) b[i] - '0';
        int val = (a_i+ b_i + carry) % 2;
        carry = (a_i + b_i + carry )/2;
        sum += (val == 1) ? string("1") : string("0");
    }
    if(carry > 0){
        sum += string("1");
    }
    reverse(sum.begin(), sum.end());
    return sum;
}

TEST(AddBinary, I){
    string a("11");
    string b("1");
    const char * sum = "100";
    ASSERT_STREQ(sum, addBinary(a, b).c_str());
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



