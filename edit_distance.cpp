#include "utils.h"

using namespace std;

/*
  From https://web.stanford.edu/class/cs124/lec/med.pdf
  For two strings: X of length n
                   Y of lenght m
  define D(i,j) as the edit distance between X[1..i] and Y[1..j]
  DP solution:
  base case:
  D(i, 0) = i
  D(0, j) = j
  general case:
  for each i = 1...m
      for each j = 1...n
          D(i, j) = min(D(i-1, j)+1,
                        D(i, j-1)+1,
                        D(i-1, j-1) + 1, X(i) != Y(i)
                        D(i-1, j-1) + 0, X(i) == Y(i))
  
 */
int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    int D[m+1][n+1];
    // initialization
    for(int i=0; i<=m; i++){
        D[i][0] = i;
    }
    for(int j=0; j<=n; j++){
        D[0][j] = j;
    }

    if(n==0 || m==0) return D[m][n];
    
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(word1.at(i-1) == word2.at(j-1))
                D[i][j] = min(min(D[i-1][j], D[i][j-1])+1, D[i-1][j-1]);
            else
                D[i][j] = min(min(D[i-1][j], D[i][j-1])+1, D[i-1][j-1]+1);
        }        
    }
    return D[m][n];
}

int main(){
    string word1("intention");
    string word2("execution");
    cout<<minDistance(word1, word2)<<endl;
    string word3("a");
    string word4("ab");
    cout<<minDistance(word3, word4)<<endl;
    return 0;
}
