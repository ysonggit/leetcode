#include "utils.h"

using namespace std;

// dfs , every time start iteration from 0
/*
  @param &results;
  @param & src
  @param & sol
  @param & used
  
  if pass the last position
     save solution and return
  index start from 0 to last position
     if current is marked as used continue
     if current == previous, and previous is used continue
     otherwise
        sol + current element
        mark as used
        dfs
        mark as not used
        sol - current element  
 */

void dfs(vector<vector<int> > &results, vector<int> & num, vector<int> & sol, bool * used){
    if(sol.size() == num.size()){
        results.push_back(sol);
        return ;
    }
    for(int i=0; i<num.size(); i++){
        if(used[i]) continue;
        if((i>0 && num[i]==num[i-1] && used[i-1] ) ) continue;
        sol.push_back(num[i]);
        used[i] = true;
        dfs(results, num, sol, used);
        used[i] = false;
        sol.pop_back();
    }
}

vector<vector<int> > permuteUnique(vector<int> &num) {
    vector<vector<int> > results;
    int n = num.size();
    if(n == 0) return results;
    sort(num.begin(), num.end());
    vector<int> sol;
    bool * used = new bool[n];
    for(int i=0; i<n; i++){
        used[i] = false;
    }
    dfs(results, num, sol, used);
    delete [] used;
    used = NULL;
    return results;
}


int main(int argc, char *argv[])
{
    vector<int> num{1,2,1};
    vector<vector<int> > res = permuteUnique(num);
    print2DVector(res);
    return 0;
}
