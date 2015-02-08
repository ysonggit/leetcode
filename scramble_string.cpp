#include "utils.h"
#include <gtest/gtest.h>

using namespace std;

/*
  idea : what does the binary tree implicate?
         ____________________
         |                  |
      -- |divide and conquer| OR binary search OR DFS/BFS
         |__________________|
  given two strings s1, s2
  recursively divide each string into two parts s1=s11+s12, s2=s21+s22
  s1 and s2 are scrambled strings if
  isScramble(s11, s21) && isScramble(s12,s22), otherwise,
  divide s2 in another way such that s2 = s21_ + s22_
  isScramble(s11, s21_) && isScramble(s12,s22_)

  simple case: s1 = ab, s2 = ba or ab
               s1 = eat, s2 = tae        or ate
                    /  \      /  \          / \
                   e   at    ta   e        at  e
                       /\    /\
                      a  t  t  a
  base case:
  if both empty, true
  if both one char, true iff s1 == s2
  
 */

bool isScramble(string s1, string s2) {
    if(s1.empty()) return s2.empty();
    if(s1.length()==1) return s1 == s2;
    int n = s1.length(), m = s2.length();
    // cout<<s1<<", "<<s2<<endl;
    if(n != m) return false;
    // pruning 1:
    // sort the characters, if sorted string are not equal, then false
    string _s1(s1), _s2(s2);
    sort(_s1.begin(), _s1.end());
    sort(_s2.begin(), _s2.end());
    if (_s1 != _s2) return false;
    // divide strings into two parts
    // pruning 2:
    // use a boolean to control the loop, jump of the loop one the scramble is confirmed
    bool is_scramble = false;
    for(int i=1; i<n && !is_scramble; i++){
        string s11 = s1.substr(0,i);
        string s12 = s1.substr(i);
        string s21 = s2.substr(0,i);
        string s22 = s2.substr(i);
        is_scramble = isScramble(s11, s21) && isScramble(s12, s22);
        if(!is_scramble){
            string s21_ = s2.substr(n-i,i);
            string s22_ = s2.substr(0,n-i);
            is_scramble = isScramble(s11, s21_) && isScramble(s12, s22_);
        }
    }
    return is_scramble;
}

TEST(Scramble, I){
    string s1("great");
    string s2("rgeat");
    bool res= true;
    ASSERT_EQ(res, isScramble(s1,s2));
}

TEST(Scramble, II){
    string s1("great");
    string s2("rgtae");
    bool res= true;
    ASSERT_EQ(res, isScramble(s1,s2));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


