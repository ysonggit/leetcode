#include "utils.h"
#include <gtest/gtest.h>
#include <unordered_map>

using namespace std;

/*
  '.' Matches any single character.
  '*' Matches zero or more of the preceding element.
  
  if next char of p is NOT '*', it must match current char of s.
  continue matching s+1 and p+1

  if next char of p is '*':
  p[j] | p[j+1] | p[j+2] | ...
  x(.) |  *     |  y(.)  | ...   
  means current s[i].. s[i+k] may match p[j]
  then recursively matching
  match s[i], s[i+1], ... s[i+k] with p[j+2],
  until we could not find the matching

  question: two empty char return true or false?
 */
/*
bool isMatch(const char *s, const char *p) {
    if(*p=='\0') return *s=='\0';
    if(*(p+1) != '*'){
        // tricky: must have  both *s !='\0' &&  *p != '.'
        // otherwise, case s = “abcbcd”, p = “a.*c.*d” can not be correctly judged
        if(!(*s == *p || (*s!='\0' && *p=='.'))) return false;
        return isMatch((s+1), (p+1)) ;
    }
    // next char of p is '*'
    while((*s != '\0' && *p=='.') || (*s == *p) ){
        // recursively check s[i]...s[i+k] with p[j+2]
        // backtracking method
        if(isMatch(s, p+2)) return true;
        s++;
    }
    return isMatch(s, p+2); // case s="aa", p=".*"
}*/
/*
  DP solution:
 have a bool matrix to save previous results
 define M[i][j] : the first i bits of s, s[0,..i-1], matches the first j bits of p p[0,..j-1]
 1. if p[j] is Not '*'
    M[i+1][j+1] =  M[i][j] && s[i] == p[j]  or p[j] is a . 
 2. if p[j] is '*'
    if p[j-1] is NOT '.':
          M[i+1][j+1] = M[i+1][j]                 s="aa"  p="a*"
                        M[i+1][j-1]               s="aab" p="c*a*b"
                        M[i][j+1] && s[i] == s[i-1] && s[i-1] = p[j-1] s="abbbc" p="ab*c"
    if p[j-1] is '.':
          M[i+1][j+1] = M[i+1][j-1] || M[i+1][j]  s="aa" p=".*"
                                                  s="ab" p=".*"
                                                  s="abcbcd" p="a.*c.*d"
     
 */

bool isMatch(const char *s, const char *p) {
    if(*p=='\0') return *s == '\0';
    const int n = strlen(s);
    const int m = strlen(p);
    vector<vector<int> > M(n+1, vector<int>(m+1, 0));
    // tricky initialization :
    // what is value of M[0][j] : the possible p to match an empty s:
    // s="" how about p="a*" or "*****" or "a*bcd*"
    M[0][0] = 1; //base case: empty string
    M[0][1] = (p[0] == '*' ) ? 1 : 0;
    for(int j=2; j<=m; j++){
        if(p[j-1]=='*') {
            M[0][j] = M[0][j-2];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(p[j]!='*'){
                M[i+1][j+1] = M[i][j] && (s[i] == p[j] || p[j] == '.');
            }else{
                if(j>0 && p[j-1] != '.'){
                    M[i+1][j+1] = M[i+1][j] || M[i+1][j-1];
                    if(i>0)
                       M[i+1][j+1] = M[i+1][j+1] || (M[i][j+1] && s[i]==s[i-1] && s[i-1]==p[j-1]);
                }
                if(j>0 && p[j-1] =='.'){
                    if(M[i+1][j-1] != 0 || M[i+1][j] !=0){
                        for(int k=i+1; k<=n; k++){
                            M[k][j+1] = 1;
                        }
                    }
                }
            }
        }
    }
    // print2DVector(M);
    return M[n][m];
}


TEST(REGEX, I){
    const char * s = "abbbc";
    const char * p = "ab*c";
    bool res = true;
    ASSERT_EQ(res, isMatch(s,p));
}

TEST(REGEX, II){
    const char * s = "ac";
    const char * p = "ab*c";
    bool res = true;
    ASSERT_EQ(res, isMatch(s,p));
}
TEST(REGEX, III){
    const char * s = "abc";
    const char * p = "abc";
    bool res = true;
    ASSERT_EQ(res, isMatch(s,p));
}
TEST(REGEX, IV){
    const char * s = "aaa";
    const char * p = "aa";
    bool res = false;
    ASSERT_EQ(res, isMatch(s,p));
}
TEST(REGEX, V){
    const char * s = "aa";
    const char * p = ".*";
    bool res = true;
    ASSERT_EQ(res, isMatch(s,p));
}
TEST(REGEX, VI){
    const char * s = "ab";
    const char * p = ".*";
    bool res = true;
    ASSERT_EQ(res, isMatch(s,p));
}
TEST(REGEX, VII){
    const char * s = "aab";
    const char * p = "c*a*b";
    bool res = true;
    ASSERT_EQ(res, isMatch(s,p));
}
TEST(REGEX, VIII){
    const char * s = "abcbcd";
    const char * p = "a.*c.*d";
    bool res = true;
    ASSERT_EQ(res, isMatch(s,p));
}
TEST(REGEX, IX){
    const char * s = "abcd";
    const char * p = "d*";
    bool res = false;
    ASSERT_EQ(res, isMatch(s,p));
}
TEST(REGEX, X){
    const char * s = "aaa";
    const char * p = "aaaa";
    bool res = false;
    ASSERT_EQ(res, isMatch(s,p));
}
TEST(REGEX, XI){
    const char * s = "a";
    const char * p = "ab*a";
    bool res = false;
    ASSERT_EQ(res, isMatch(s,p));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
