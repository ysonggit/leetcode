#include "utils.h"

using namespace std;

/*
  dfs search
 */

void dfs(vector<vector<int> > &results, const vector<int>&candidates, vector<int> sol, int start, int target){
    if(start > candidates.size() ||  target<0) return;
    if(target== 0){
        results.push_back(sol);
        return;
    }
 
    for(int i=start; i<candidates.size(); i++){
        if(i>0 && candidates[i] == candidates[i]-1) continue;
        sol.push_back(candidates[i]);
        dfs(results, candidates, sol, i, target-candidates[i]);// tricky, here pass i not i+1 because the same number can be used infinite times
        sol.pop_back();
    }
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    vector<vector<int> > results;
    if(candidates.size() ==0) return results;
    sort(candidates.begin(), candidates.end());
    vector<int> sol;
    dfs(results, candidates, sol, 0, target);
    return results;
}

int main(int argc, char *argv[])
{
    vector<int> inputs{2,3,6,7};
    int target = 7;
    vector<vector<int> > combs = combinationSum(inputs, target);
    print2DVector(combs);
    vector<int> inputs1{1,3};
    int target1 = 2;
    vector<vector<int> > combs1 = combinationSum(inputs1, target1);
    print2DVector(combs1);
    return 0;
}
