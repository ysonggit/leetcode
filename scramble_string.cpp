#include "utils.h"
#include <gtest/gtest.h>

using namespace std;

/*
  idea : what could a binary tree implicate?
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

  26ms
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

/*
  DP 
  define D[k][i][j]: D[k][i][j] is true means
                       the substring starting from s2[j] ending at j+k (s2[j...j+k])
                       is a scramble of s1 starting from i, that is s[i...i+k]

  transition equation
  D[len-1][i][j] is true means s1[i...i+len-1] and s2[j..j+len-1] are scrambled
    true if D[k-1][i][j] && D[len-k-1][i+k][j+k], that is,
         s1[i..i+k-1] and s2[j..j+k] are scrambled AND
         s1[i+k..i+len-1] and s2[j+k..j+len-1] are scrambled
    OR divide in another way
         s1[i..i+k-1] and s2[j+len-k..j+len-1] are scrambled AND
         s1[i+k..i+len-1] and s2[j..j+len-k-1] are scrambled
  base case
  D[0][i][j] = (s1[i]== s2[j]) ? true : false;

  69ms
 */

bool isScramble(string s1, string s2) {
    if(s1.empty()) return s2.empty();
    if(s1.length()==1) return s1 == s2;
    const int n = s1.length(), m = s2.length();
    if(n!=m) return false;
    bool D[n][n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            D[0][i][j] = (s1[i]== s2[j]) ? true : false;
        }
    }
    for(int len=2; len<=n; len++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                bool is_scramble = false;
                for(int k=1; k<len && !is_scramble; k++){
                    is_scramble = (D[k-1][i][j] && D[len-k-1][i+k][j+k]) ||
                        (D[k-1][i][j+len-k] && D[len-k-1][i+k][j]);
                }
                D[len-1][i][j] = is_scramble;
            }
        }
    }
    return D[n-1][0][0]; 
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


