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
     if current is marked as used continue to next element
     else
        sol + current element
        mark as used
        dfs
        mark as not used
        sol - current element  
 */

void dfs(vector<vector<int> > &results, vector<int> & num, vector<int> & sol, vector<int> & visited){
    if(sol.size() == num.size()){
        results.push_back(sol);
        return;
    }
    for(int i=0; i<num.size(); i++){
        if(visited[i]==0){
            visited[i] = 1;
            sol.push_back(num[i]);
            dfs(results, num, sol, visited);
            sol.pop_back();
            visited[i] = 0;
        }
    }
}

vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > results;
    int n = num.size();
    if(n ==0) return results;
    vector<int> sol;
    vector<int> visited(n, 0);
    dfs(results, num, sol, visited);
    return results;
}


int main(int argc, char *argv[])
{
    vector<int> num{1,2,3};
    vector<vector<int> > res = permute(num);
    print2DVector(res);
    return 0;
}
