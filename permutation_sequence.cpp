#include "utils.h"

using namespace std;

/*
  dfs template for permutations
  @param & results
  @param n
  @param sol
  @param used

  if sol.size == n
     results.add(sol)
     return

  if (results.size == k) return
  for each i =0 ...n-1
      if i is not used
         sol.push_back(char_i)
         used[i] = true
         dfs(results, n, sol, used)
         used[i] = false
         sol.pop_back
 */
void dfs(vector<string> & results, vector<int> & sol, int n, int k, int & count, bool *used){
    if(count>k) return;
    if(sol.size()==n){
        count++;
        if(count==k){
            stringstream ss;
            for(int i : sol){
                ss<<i;
            }
            results.push_back(ss.str());
        }
        return;
    }
    for(int i=0; i<n; i++){
        if(!used[i]){
            sol.push_back(i+1);
            used[i] = true;
            dfs(results, sol, n, k, count, used);
            used[i] = false;
            sol.pop_back();
        }
    }
}

string getPermutation(int n, int k) {
    if(n<=0 || k<1 ) return string(""); // k > n! overflow
    int count = 0;
    vector<string> results;
    vector<int> sol;
    bool * used = new bool[n];
    for(int i=0; i<n; i++){
        used[i] = false;
    }
    dfs(results, sol, n, k, count, used);
    delete [] used;
    used = NULL;
    return results[0];
}

int main(int argc, char *argv[])
{
    cout<<getPermutation(9, 155915)<<endl;
    return 0;
}
