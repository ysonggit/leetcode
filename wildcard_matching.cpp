#include "utils.h"
#include <gtest/gtest.h>

using namespace std;
/*
  idea: DP O(n^2) time O(n^2) space
  define D[i][j] to represent the first i bits of s (s[0..i-1])
  matches the first j bits of p (p[0...j-1])

  transition equation:
  no * (kleene closure) 
  D[i][j] is true if D[i-1][j-1] is true and s[i-1]==p[j-1] || p[j-1] is ?

  meet a *
  D[i][j] is true if
  1) D[i-1][j-1] is true, means first i-1 bits of s matches first j-1 bits of p, also for D[i+1][j]... D[n][j] is true

  2) D[i][j-1] is true, means first i bits of s matches first j-1 bits of p,
  for example s="abaa", p="*a*"

  Memory Limit Exceeded
 */

bool isMatch(const char *s, const char *p) {
    const int n = strlen(s);
    const int m = strlen(p);
    if(*s=='\0') return *p=='\0' || *p == '*'; 
    vector<vector<int> > D(n+1, vector<int>(m+1, 0));
    //initialize D for base case
    D[0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(p[j-1] != '*'){
                D[i][j] = D[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='?');
            }else{
                if(D[i-1][j-1]!=0){
                    for(int k=i-1; k<=n; k++){
                        D[k][j]=1;
                    }
                }
                if(D[i][j-1]!=0){
                    for(int k=i; k<=n; k++){
                        D[k][j] = 1;
                    }
                }
            }
        }
    }
    //print2DVector(D);
    return (D[n][m]==1) ? true : false;
}

TEST(Matching, I){
    const char *s="aa";
    const char *p="a";
    bool res = false;
    ASSERT_EQ(res, isMatch(s,p));
}

TEST(Matching, II){
    const char *s="aa";
    const char *p="aa";
    bool res = true;
    ASSERT_EQ(res, isMatch(s,p));
}


TEST(Matching, III){
    const char *s="aaa";
    const char *p="aa";
    bool res = false;
    ASSERT_EQ(res, isMatch(s,p));
}


TEST(Matching, IV){
    const char *s="aa";
    const char *p="*";
    bool res = true;
    ASSERT_EQ(res, isMatch(s,p));
}


TEST(Matching, V){
    const char *s="aa";
    const char *p="a*";
    bool res = true;
    ASSERT_EQ(res, isMatch(s,p));
}


TEST(Matching, VI){
    const char *s="ab";
    const char *p="?*";
    bool res = true;
    ASSERT_EQ(res, isMatch(s,p));
}


TEST(Matching, VII){
    const char *s="aab";
    const char *p="c*a*b";
    bool res = false;
    ASSERT_EQ(res, isMatch(s,p));
}


int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}




