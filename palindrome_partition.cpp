#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*  DFS O(2^n)
    find palindrome in s[0] and  find palindrome in s[1:end-1]
    find palindrome in s[0:1] and  find palindrome in s[2:end-1]
    ...
    find palindrome in s[0:end-2] and  find palindrome in s[end-1]
*/
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

/* DP: Refer Palindrome Partation II O(n^2)
   create a 2D table P(i,j) : true if s[i..j] is a palindrome
   // other's solution 62ms

vector<vector<string>> partition(string s){
    const int n = s.length();
    vector<vector<string> > results;
    if(n==0) return results;
    bool P[n][n];
    fill_n(&P[0][0], sizeof(P)/sizeof(**P), false);
    //vector<vector<int> > P(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        P[i][i] = true;
    }
    for(int L=2; L<=n; L++){
        // for each substring of length L = 2...n
        for(int i=0; i<=n-L; i++){
            // the possible palindrome substring may start at pos i = 0... n-L
            int j = i+L-1; // the possible palindrome substring ends at j
            if(L==2){
                P[i][j] = (s[i]==s[j]);
            }else{
                P[i][j] = (s[i]==s[j] && P[i+1][j-1]);
            }
        }
    }

    vector<vector<string> > sub_palins[n];
    for(int i=n-1; i>=0; i--){
        for(int j=i; j<n; j++){
            if(P[i][j]){
                string palindrome = s.substr(i, j-i+1);
                if(j+1<n){
                    for(auto v: sub_palins[j+1]){
                        v.insert(v.begin(), palindrome);
                        sub_palins[i].push_back(v);
                    }
                }else{
                    sub_palins[i].push_back(vector<string>{palindrome});
                }
            }
        }
    }
    return sub_palins[0];
}
 */ 

void showResults(const vector<vector<string> >& results){
    for(vector<string> vs : results){
        for(string s: vs){
            cout<<s<<" ";
        }
        cout<<endl;
    }
}

int main(){
    string s("ltsqjodzeriqdtyewsrpfscozbyrpidadvsmlylqrviuqiynbscgmhulkvdzdicgdwvquigoepiwxjlydogpxdahyfhdnljshgjeprsvgctgnfgqtnfsqizonirdtcvblehcwbzedsmrxtjsipkyxk"
);
    vector<vector<string> > results = partition(s);
    showResults(results);
    return 0;
}
