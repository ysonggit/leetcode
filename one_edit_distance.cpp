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
    if(s.empty() && t.empty()) return false;
    int m = s.length(), n = t.length();
    if(abs(m-n)> 1) return false;
    if(m==n){
        // sequentially compare each character in s and t respectively (linear forward search),
        // find the different one(s), if there exits the only one character that is different in two strings
        // return true, otherwise, false
        int count = 0;
        for(int i=0; i<m; i++){
            if(s[i]==t[i]){
                count++;
            }
        }
        if(m-count==1) return true;
        return false;
    }
    // check if insertion or deletion makes two strings equal
    // idea: for each character in the longer string
    //           delete it and compare with the shorter one
    //           if substr is equal to the shorter
    //               return true
    // s = abcdefg
    // t = abcddefg
    string longer = (m>n) ? s : t;
    string shorter = (m>n) ? t : s;
    for(int pos=0; pos<longer.length(); pos++){
        //1. save a copy of char at pos
        char c = longer[pos];
        //2. remove this char 
        longer.erase(pos, 1);
        if(longer==shorter) return true;
        longer.insert(pos, 1, c);
    }
    return false;
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

