#include "utils.h"
#include <unordered_set>

using namespace std;
/*
  DP
  define f(i) : s[0,i] can be broken into words
  f(i) = any_of (f(k) && s[k+1, i] is in dict) 0<=k < i
  base case:
  f(0) is true empty string
  for example s="catsanddog"
   f[10] ={true, false, false, true, true, false, false, true, false, false, true}
 */
bool wordBreak(string s, unordered_set<string> & dict){
    int n = s.length();
    vector<int> f(n+1, 0);
    f[0] = 1;
    for(int i=1; i<=n; i++){
        for (int k=0; k<i; k++) {
            if(f[k] && dict.find(s.substr(k, i-k))!= dict.end() ){// not k+1
                f[i] = 1;
                break;
            }
        }
    }
    //printVector(f);
    return f[n];
}

int main(int argc, char *argv[]){
    string s("catsanddog");
    unordered_set<string> dict ={"cat", "cats", "sand", "and", "dog"};
    if(wordBreak(s, dict)){
        cout<<"can be segmented into words\n";
    }
    return 0;
}

