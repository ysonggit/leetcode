#include "utils.h"
#include <gtest/gtest.h>

using namespace std;
/*http://www.geeksforgeeks.org/dynamic-programming-set-17-palindrome-partitioning/
  idea: DP O(n^3) 
  define f(i,j) : the minimal cuts to make palidrome partations from s[i..j]
  f(i,j) = 0       if i == j or s[i..j] is palindrome
       = argmin { f(i, k) + 1 + f(k+1, j) }
         k = i ... j-1
  TIME LIMIT EXCEEDED
  int minCut(string s){
    const int n = s.length();
    if(n==0) return 0;
    // P[i][j] : true if s[i..j] is a palindrome
    // DP transition: P(i,j) = s[i] == s[j] && P(i+1, j-1)
    bool P[n][n];
    fill_n(&P[0][0], sizeof(P)/sizeof(**P), false);
    //vector<vector<int> > P(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        P[i][i] = true;
    }
    vector<vector<int> > f(n, vector<int>(n, 0));
    for(int L=2; L<=n; L++){ // check substring with length L = 2 ... n
        for(int i=0; i<=n-L; i++){ // starting idx of substring of length L
            int j = i+L-1; // ending idx of substring of length L
            if(L==2 ){
                P[i][j] = (s[i]== s[j]);
            }else{
                P[i][j] = (s[i]==s[j] && P[i+1][j-1]);
            }
            if(P[i][j]){
                f[i][j] = 0;
                f[j][i] = 0;
            }else{
                int local_min_cuts = INT_MAX;
                for(int k=i; k<j; k++){
                    local_min_cuts = min(local_min_cuts, f[i][k]+1+f[k+1][j]);
                }
                f[i][j] = local_min_cuts;
            }
        }
    }
    print2DVector(f);
    return f[0][n-1];
    }*/

/*
  Optimized version
  Refer Word Break: reduce 2D DP to 1D DP
  idea: DP O(n^2) 
  define f(i) : the minimal cuts to make palindrome partations from s[0..i]
  f(i) = 0       if s[0...i] is palindrome
       = argmin { f(j) + 1}  if s[j+1..i] is a palindrome
         j = 0 ... i-1
*/
int minCut(string s){
    const int n = s.length();
    if(n==0) return 0;
    // P[i][j] : true if s[i..j] is a palindrome
    // DP transition: P(i,j) = s[i] == s[j] && P(i+1, j-1)
    bool P[n][n];
    fill_n(&P[0][0], sizeof(P)/sizeof(**P), false);
    //vector<vector<int> > P(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        P[i][i] = true;
    }
    vector<int> f(n, INT_MAX);
    for(int L=2; L<=n; L++){ // check substring with length L = 2 ... n
        for(int i=0; i<=n-L; i++){ // starting idx of substring of length L
            int j = i+L-1; // ending idx of substring of length L
            if(L==2 ){
                P[i][j] = (s[i]== s[j]);
            }else{
                P[i][j] = (s[i]==s[j] && P[i+1][j-1]);
            }
        }
    }
    for(int i=0; i<n; i++){
        if(P[0][i]){
            f[i] = 0;
        }else{
            for(int j=0; j<i; j++){
                if(P[j+1][i])  f[i] = min(f[i], f[j]+1);
            }
        }
    }
    // printVector(f);
    return f[n-1];
    }


TEST(PalindromePartation, I){
    string s("aab");
    int res = 1;
    ASSERT_EQ(res, minCut(s));
}

TEST(PalindromePartation, II){
    string s("aabcdaa");
    int res = 4;
    ASSERT_EQ(res, minCut(s));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}




