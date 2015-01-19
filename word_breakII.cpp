#include "utils.h"
#include <unordered_set>

using namespace std;
/*
  1.   DP O(n^2)
  define f(i) : s[0,i] can be broken into words 
  define wd[k][j] : s[k, j] is a word in the dict
  f(i) = any_of (f(k) && s[k+1..i] is in dict) 0<=k < i (length of s[k+1, i] is i-k)
         wd[k+1][i] is true
  base case:
  f(0) is true empty string
  2. 
  DFS
  @param results
  @param s
  @param sol
  @param cur_idx
  @param wd

   if (cur_idx>=s.length){
      generate sentence
      save sentence to results and return
   }
   for(int i=0; i<s.length; i++){
      if(wd[cur_idx][i]==1){
         sol.push_back(s[cur_idx...i])
         dfs(results, s, sol, i+1, wd)
         sol.pop_back
      }
   }
   for example s="catsanddog"
   f[10] ={false, false, true, true, false, false, true, false, false, true}
 */
void dfs(vector<string> & results, string & s, vector<string> & sol, int cur_idx, vector<vector<int> > & wd){
    if(cur_idx>= s.length()){
        string sentence;
        for(int i=0; i<sol.size()-1; i++){
            sentence += sol[i];
            sentence += string(" ");
        }
        sentence += sol[sol.size()-1];
        results.push_back(sentence);
        return ;
    }
    for (int i=0; i<s.length(); i++){
        if(wd[cur_idx][i]==1){
            sol.push_back(s.substr(cur_idx, i-cur_idx+1));
            dfs(results, s, sol, i+1, wd);
            sol.pop_back();
        }
    }
}

vector<string> wordBreak(string s, unordered_set<string> & dict){
    vector<string> results;
    if(s.empty()) return results;
    int n = s.length();
    vector<int> f(n+1, 0);
    f[0] = 1;
    vector<vector<int> > wd(n, vector<int>(n, 0));
    for(int i=1; i<=n; i++){
        for(int k=0; k<i; k++){
            if(f[k] == 1 && dict.find(s.substr(k, i-k))!= dict.end()){
                f[i] = 1;
                wd[k][i-1] = 1;
            }
        }
    }
    // printVector(f);
    // print2DVector(wd);
    // tricky: first check if the given string can be broken into valid words
    // otherwise, time limit exceeded
    if(f[n]==1){
        vector<string> sol;
        dfs(results, s, sol, 0, wd);
    }
    return results;
}

int main(int argc, char *argv[]){
    string s("catsanddog");
    unordered_set<string> dict ={"cat", "cats", "sand", "and", "dog"};
    vector<string> results = wordBreak(s, dict);
    printVector(results);
    return 0;
}

