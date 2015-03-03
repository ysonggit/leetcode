#include <gtest/gtest.h>
#include "utils.h"

using namespace std;
/*
  given n , generate n-th sequence
  example , n = 5
  1, 11, 21, 1211, 111221, ...
  n=1, generate 1
  n=2, check n=1 results, one 1, so generate 11
  n=3, check n=2 results, two 1s, so generate 21
  n=4, last result of n=3 is 21, read as one 2 one 1, so generate 1211
  n=5, last one is 1211, read as one 1 one 2 two 1s, so generate 111221
  n=6, read 111221 as three 1s two 2s, one 1, so generate 312211

  therefore, the idea is:
  1. for the same number, count the times it repeats,
  for example, 111221, count three 1s, count two 2s, count one 1
  2. concatenate the repeated time with the repeated number

  seems 0 will never show up
 */
void helper(string & pre_str, int cur, int & n){
    if(cur == n) return;
    string new_str;
    // for the same number in s, count frequency
    int i = 0;
    while(i<pre_str.length()){
        int j = i + 1;
        while(j < pre_str.length() && pre_str[i] == pre_str[j]){
            j++;
        }
        stringstream ss;
        ss<<(j-i)<<pre_str[i];
        new_str += ss.str();
        i = j;
    }
    pre_str = new_str;
    helper(pre_str, cur+1, n);
}

string countAndSay(int n){
    if(n<=0) return string("");
    string res("1");
    if(n==1) return res;
    helper(res, 1, n);
    return res;
}

TEST(CountAndSay, I){
    int n=1;
    const char * res ="1";
    ASSERT_STREQ(res, countAndSay(n).c_str());
}

TEST(CountAndSay, II){
    int n=2;
    const char * res ="11";
    ASSERT_STREQ(res, countAndSay(n).c_str());
}

TEST(CountAndSay, III){
    int n=3;
    const char * res ="21";
    ASSERT_STREQ(res, countAndSay(n).c_str());
}


TEST(CountAndSay, IV){
    int n=4;
    const char * res ="1211";
    ASSERT_STREQ(res, countAndSay(n).c_str());
}


int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



