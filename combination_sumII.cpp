#include "utils.h"

using namespace std;

/*
  dfs search
 */

void dfs(vector<vector<int> > &results, const vector<int>&candidates, vector<int> sol, int start, int target){
    if(start > candidates.size() || target<0) return;
    if(target== 0 ){
        results.push_back(sol);
        return;
    }
 
    for(int i=start; i<candidates.size(); i++){
        if(i>start && candidates[i]==candidates[i-1]) continue; // tricky: prevent using previously used duplicated number
        sol.push_back(candidates[i]);
        dfs(results, candidates, sol, i+1, target-candidates[i]);//here pass i+1 because the each number can be used only once
        sol.pop_back();
    }
}

vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int> > results;
    if(candidates.size() ==0) return results;
    sort(candidates.begin(), candidates.end());
    vector<int> sol;
    dfs(results, candidates, sol, 0, target);
    return results;
}

int main(int argc, char *argv[])
{
    vector<int> inputs{10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int> > combs = combinationSum2(inputs, target);
    print2DVector(combs);
    return 0;
}
