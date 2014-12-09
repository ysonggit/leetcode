#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool isPalindrome(string s){
    if(s.length()==0) return false;
    for(int i=0; i<s.length()/2; i++){
	if(s[i] != s[s.length()-1-i]){
	    return false;
	}
    }
    return true;
}
    
void dfs(vector<vector<string> > & results, vector<string> & sol, string s, int start_idx){
    if(start_idx == s.length()){
	results.push_back(sol);
	return;
    }
    for(int i=start_idx; i<s.length(); i++){
	// check s[0:i]
	string subs = s.substr(start_idx, i-start_idx+1);
	if(isPalindrome(subs)){
	    sol.push_back(subs);
	    
	    dfs(results, sol, s, i+1);
	    sol.pop_back();    
	}
    }
} 
    
vector<vector<string>> partition(string s) {
    vector<vector<string> > results;
    if(s.length()<=0) return results;
    vector<string> sol;
    dfs(results, sol, s, 0);
    return results;
}

void showResults(const vector<vector<string> >& results){
    for(vector<string> vs : results){
	for(string s: vs){
	    cout<<s<<" ";
	}
	cout<<endl;
    }
    cout<<endl;
}

int main(){
    string s("a");
    vector<vector<string> > results = partition(s);
    showResults(results);
    return 0;
}
