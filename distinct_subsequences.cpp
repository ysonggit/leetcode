#include "utils.h"
#include <gtest/gtest.h>

using namespace std;

/* DP: let D[i][j] be the number of distinct subsequences start from 0 to i in s
                                that matches the substring start form 0 to j in t

   D[i][j] = D[i-1][j] + D[i-1][j-1]   s[i] == t[j] 
           = D[i-1][j]                 s[i] != t[j]

   for example: s="abbdd", t="bd"
   since s[4]==t[1] D[4][1] = D[3][1] + D[3][0]
   means "abbd" already contains "bd" or "abbdd" still contains "bd"
   question: how about t is empty?
 */

int numDistinct(string S, string T) {
    if(S.empty() || T.empty() || S.length() < T.length()) return 0;
    const int m = S.length(), n = T.length();
    int D[m+1][n+1];
    for(int j=0; j<=n; j++){
        D[0][j] = 0;
    }
    // tricky initialization :
    // in each row the first element should be initialized as 1
    // so that when s[1] == t[1],D[1][1] = 1...
    for(int i=0; i<=m; i++){
        D[i][0] = 1;
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            // be careful of S[i-1] and T[j-1]
            D[i][j] = (S[i-1] == T[j-1]) ? D[i-1][j] + D[i-1][j-1] : D[i-1][j];
        }
    }
    return D[m][n];
}

TEST(NumDistinctSubseq, One){
    string s("rabbbit");
    string t("rabbit");
    int res= 3;
    ASSERT_EQ(res, numDistinct(s, t));
}

TEST(NumDistinctSubseq, Two){
    string s("ABCDE");
    string t("ACE");
    int res= 1;
    ASSERT_EQ(res, numDistinct(s, t));
}

TEST(NumDistinctSubseq, Three){
    string s("ABCD");
    string t("BD");
    int res= 1;
    ASSERT_EQ(res, numDistinct(s, t));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


