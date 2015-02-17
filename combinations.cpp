#include "utils.h"
#include <gtest/gtest.h>
using namespace std;

/*
  idea :
  dfs:  use count to control termination
  
 */
void dfs(vector<vector<int> >& results,
    vector<int> & sol,
    int start_idx,
    int count,
    int n,
    int k)
{
    if(count == k){
        results.push_back(sol);
        return ;
    }
    for(int i=start_idx; i<n; i++){
        sol.push_back(i+1);
        dfs(results, sol, i+1, count+1,  n, k);
        sol.pop_back();
    }
}

vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > results;
    if(k>n || n==0 || k==0) return results;
    vector<int> sol;
    dfs(results, sol, 0, 0, n, k);
    return results;
}

int main(int argc, char *argv[]){
    print2DVector(combine(4,2));
    return 0;
}



