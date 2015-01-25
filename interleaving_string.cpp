#include "utils.h"
#include <gtest/gtest.h>

using namespace std;
/*
  DP:
  Define D[i][j] is true if s3[0...i+j-1] (length of i+j)
  can be interleaved by s1[0..i-1] and s2[0...j-1]
  if n = s1.length, m= s2.length
  we have D[n+1][m+1]
  base case:
  D[0][0] is true empty string
  D[1][0] is true if s3[0] == s1[0]
  D[0][1] is true if s3[0] == s2[0]

  s3[0...i+j-1] is interleaved string if s3[0,i+j-2] is interleaved string of s1 and s3
                     and s3[i+j-1] == s1[i-1] or s2[j-1]
  that is
  D[i][j] = D[i-1][j] && s3[i+j-1] == s1[i-1]
            OR
            D[i][j-1] && s3[i+j-1] == s2[j-1]
 
 */

bool isInterleave(string s1, string s2, string s3) {
    int n = s1.length();
    int m = s2.length();
    int k = s3.length();
    if(k == 0) return true;
    if(k != m+n) return false;
    vector<vector<int> > D(n+1, vector<int>(m+1, 0));
    D[0][0] = 1;
    for(int j=1; j<=m; j++){
        D[0][j] = (s3.substr(0,j) == s2.substr(0,j)) ? 1 : 0;
    }
    for(int i=1; i<=n; i++){
        D[i][0] = (s3.substr(0,i) == s1.substr(0,i)) ? 1 : 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if((D[i-1][j]==1 && s3[i+j-1]== s1[i-1])||
                (D[i][j-1]==1 && s3[i+j-1]==s2[j-1])){
                D[i][j]=1;
            }
        }
    }
    print2DVector(D);
    return (D[n][m]==1) ? true : false;
}

TEST(Interleaving, I){
    string s1("aabcc");
    string s2("dbbca");
    string s3("aadbbcbcac");
    string s4("aadbbbaccc");
    ASSERT_EQ(true, isInterleave(s1, s2, s3));
    ASSERT_EQ(false, isInterleave(s1, s2, s4));
}

TEST(Interleaving, II){
    string s1("a");
    string s2("");
    string s3("c");
    ASSERT_EQ(false, isInterleave(s1, s2, s3));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


