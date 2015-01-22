#include "utils.h"
#include <gtest/gtest.h>

using namespace std;
/*
  idea : brute-force (40ms)
  n = text.length, m = pattern.length
  for i = 0 .. n-m
    cout = 0
    for j = 0 .. m
      if (text[i+j] != pattern[j]) break;
      else count++

      if count ==m return i

  return -1

  KMP:
  http://www.cs.princeton.edu/courses/archive/fall04/cos226/lectures/string.4up.pdf
    1) do not backup i
    2) pre-compute next table (DFA representation of pattern)

  Be careful of dealing with corner case:
  if pattern is empty, then return 0 regardless of text's size
 */

int strStr(char * haystack,  char * needle){
    const int n = strlen(haystack);
    const int m = strlen(needle);
    if(m==0 ) return 0;
    if(m>n || m==0) return -1;
    // precompute next table
    // index of state X 
    int X = 0; 
    vector<int> next(m, 0);
    for(int j=1; j<m; j++){
        if(needle[X] == needle[j]){
            next[j] = next[X];
            X++;
        }else{// not match
            next[j] = X + 1;
            X = next[X]; 
        }
    }
    //printVector(next);
    for(int i=0, j=0; i<n; i++){
        if(haystack[i] == needle[j]) j++;
        else j = next[j];
        if(j==m) return i-m+1;
    }
    return -1;
}

TEST(Strstr, I){
    char heystack[] = "aaabaabaaab";
    char needle[] = "aabaaa";
    int res = 4;
    ASSERT_EQ(res, strStr(heystack, needle));
}

TEST(Strstr, II){
    char heystack[] = "";
    char needle[] = "";
    int res = 0;
    ASSERT_EQ(res, strStr(heystack, needle));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

