#include "utils.h"

using namespace std;

/*
  DP:
  Define P(i, j) : the palindrome of s[i]..s[j]
  P(i, j) is palindrome iff
  1. P(i+1, j-1) is palindrome
  2. s[i] == s[j]

  P(i, j) =  s[i] == s[j] , j=i+1
          =  P(i+1, j-1) && s[i] == s[j] , j>i+1
          
  base case
  P(i,i) is always a palindrome
  
*/
/*
string longestPalindrome(string s) {
    int n = s.length();
    if(n==0) return string("");
    bool P[n][n];
    int max_length = 1;
    int start_idx = 0;
    for(int i=0; i<n; i++){
        P[i][i] = true;
    }
    
    for(int i=0; i<n-1; i++){
        if(s[i] == s[i+1]){
            P[i][i+1] = true;
        }
    }

    for(int j=0; j<n; j++){
        for(int i=0; i<j; i++){
            P[i][j] =(s[i]==s[j] && P[i+1][j-1]);
            if(j-i+1 > max_length && P[i][j]){
                max_length = j-i+1;
                start_idx = i;
            }
        }
    }
    
    return s.substr(start_idx, max_length);
}

*/
/*
  for every center, a character or a space between two chars, search for two sides
  totally 2N-1 centers
  if string length is even, left = right
                      odd , left = right - 1
  return a palindrome string
*/

string palindromeAround(string s, int left_idx, int right_idx){
    while(left_idx>=0 && right_idx <s.length() && s.at(left_idx) == s.at(right_idx)){
        left_idx--;
        right_idx++;
    }
    int len = (right_idx-1)-(left_idx+1)+1;
    return s.substr(left_idx+1, len);
}

string longestPalindrome(string s){
    string longest("");
    int n= s.length();
    if(n==0) return longest;
    for(int i=0; i<2*n-1; i++){ 
        int left_idx = i/2;
        int right_idx = i/2;
        if(i%2==1) right_idx++;
        string p = palindromeAround(s, left_idx, right_idx);
        if(p.length() > longest.length()){
            longest = p;
        }
    }
    return longest;
}

int main(){
    string s("abcddcba");
    string p = longestPalindrome(s);
    cout<<p<<endl;
    cout<<longestPalindrome(string("a"))<<endl;
    cout<<longestPalindrome(string("aa"))<<endl;
    cout<<longestPalindrome(string("aaa"))<<endl;
    cout<<longestPalindrome(string("aaaa"))<<endl;
    cout<<longestPalindrome(string("aaccddccfegad"))<<endl;
    return 0;
}
