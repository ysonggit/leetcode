#include "utils.h"
#include <gtest/gtest.h>

using namespace std;

/*
  DP:
  Define D[i] : number of ways to decode first i characters of s
  # of decode s[1:i] = # of decode s[1:i-1] if s[i] is not a valid char (10,20)
                 or  = # of decode s[1:i-1] + # of decode s[1:i-2] if s[i-2:i-1] is valid (12)
  base case :
  D[0] = 0
  D[1] = 1  if s[0] = 1...9
       = 0  if s[0] = 0
  for example:
  D[2] = 0 if  s[0..1] = 00
       = 1 if  s[0..1] = 10, or 20
       = 2 if  s[0..1] = 12
 key : check if adjacent two digits can be decoded as one char
 */


// 10 - 26
bool decodeTwoDigitsAsOneChar(const char & a, const char & b){
    if(a=='1') return true;
    if(a=='2' && b <= '6')  return true;
    return false;
}

int numDecodings(string s) {
    if(s.empty() ) return 0;
    const int n = s.length();
    vector<int> D(n+1, 0);
    D[0] = 1;
    D[1] = (s[0] > '0' && s[0]<='9') ? 1 : 0;
    for(int i=1; i<n; i++){
        if(s[i]=='0'){
            if(s[i-1]=='1'||s[i-1]=='2') {
                D[i+1] = D[i-1]; // tricky: back 2 steps : 110
            }else{
                return 0; // example: 30 can not be decoded
            }
        }else{
            if(decodeTwoDigitsAsOneChar(s[i-1], s[i])){
                D[i+1] = D[i] + D[i-1];
            }else{
                D[i+1] = D[i];
            }
        }
    }
    //printVector(D);
    return D[n];
}

TEST(DecodeWays, I){
    string s("0");
    int res = 0;
    ASSERT_EQ(res, numDecodings(s));
}

TEST(DecodeWays, II){
    string s("10");
    int res = 1;
    ASSERT_EQ(res, numDecodings(s));
}

TEST(DecodeWays, III){
    string s("12");
    int res = 2;
    ASSERT_EQ(res, numDecodings(s));
}

TEST(DecodeWays, IV){
    string s("27");
    int res = 1;
    ASSERT_EQ(res, numDecodings(s));
}

TEST(DecodeWays, V){
    string s("110");
    int res = 1;
    ASSERT_EQ(res, numDecodings(s));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

