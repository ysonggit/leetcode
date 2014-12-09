#include "utils.h"

using namespace std;

void dfs(vector<vector<int> > & results, vector<int> &S, vector<int>& sol, int start_idx){
    map<int, bool> hasDup;
    for(int i=start_idx; i<S.size(); i++){
	if(hasDup.find(S[i]) == hasDup.end()){
	    hasDup.insert(std::make_pair(S[i], true));
	    sol.push_back(S[i]);
	    results.push_back(sol);
	    dfs(results, S, sol, i+1);
	    sol.pop_back();
	}

    }
        
}
vector<vector<int> > subsetsWithDup(vector<int> &S) {
    vector<vector<int> > results;
    if(S.size()==0) return results;
    sort(S.begin(), S.end());
    vector<int> sol;
    results.push_back(sol);
    dfs(results, S, sol, 0);	
    
    return results;
}

int main(){
    vector<int> S({1,2,2});
    vector<vector<int> > subsets = subsetsWithDup(S);
    cout<<"Totally there are "<< subsets.size() <<" subsets\n";
    print2DVector(subsets);
    return 0;
}
