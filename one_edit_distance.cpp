#include "utils.h"
#include <gtest/gtest.h>

using namespace std;

/*
  idea: denote the lengths of two string as m and n
        if both empty, return false (special case)
        if |m-n| > 1 return false
        else
            if |m-n| == 1 
               return insertion/deletion makes two string equal?
            else (m==n)
               return substitution makes two string equal?
*/

bool isOneEditDistance(string s, string t) {
  if(s==t) return false;
  int m = s.length(), n = t.length();
  if(abs(m-n)>1) return false;
  if(m > n) return isOneEditDistance(t, s);
  for (int i=0; i<m; i++){
    char sc = s[i], tc = t[i];
    if(sc != tc){
        if(m<n) return s.substr(i) == t.substr(i+1);
        else{
          if(i<m-1) return s.substr(i+1) == t.substr(i+1);
          else return true;
         }
    }
  }
  return true;// mistake : s = "", t = "a"
}

TEST(OneEditDistance, One){
    string s("abcdefg");
    string t("abcddefg");
    bool res = true;
    ASSERT_EQ(res, isOneEditDistance(s, t));
}

TEST(OneEditDistance, Two){
    string s("abcdef");
    string t("abcddefg");
    bool res = false;
    ASSERT_EQ(res, isOneEditDistance(s, t));
}

TEST(OneEditDistance, Three){
    string s("abccdefg");
    string t("abcddefg");
    bool res = true;
    ASSERT_EQ(res, isOneEditDistance(s, t));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

