#include "utils.h"

using namespace std;
/*
  idea: dfs O(2^n) time O(n) space
  @param: results
  @param: S
  @param: sol
  @param: cur_idx

  to create a subset, for the element S[cur_idx] in given set S, we have two choices :
  include it, OR
  exclude it
  
 */
void dfs(vector<vector<int> > & results, vector<int> & S, vector<int> & sol, int cur_idx){
    if(cur_idx == S.size()){
        results.push_back(sol);
        return ;
    }
    // exclude S[cur_idx] and move on
    dfs(results, S, sol, cur_idx+1);
    // include S[cur_idx] in the sol
    sol.push_back(S[cur_idx]);
    dfs(results, S, sol, cur_idx+1);
    sol.pop_back();
}

vector<vector<int> > subsets(vector<int> &S){
    vector<vector<int> > results;
    if(S.empty()) return results;
    sort(S.begin(), S.end());
    vector<int> sol;
    dfs(results, S, sol, 0);
    return results;
}

int main(int argc, char *argv[])
{
    vector<int> S = {1,2,3};
    vector<vector<int> > allsets = subsets(S);
    print2DVector(allsets);
    return 0;
}


