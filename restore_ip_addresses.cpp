#include "utils.h"

using namespace std;

// valid if 1 to 3 digits
// from 0 to 255
// but non-zero number that starts from 0 is invalid : 012
bool isValid(const string  & s){
    if(s[0]=='0' && s.length()>1) return false;
    int n = stoi(s);
    return n<256;
}

void dfs(vector<string> & results, const string & s, string sol, int start_idx, int count){
    if(count==4 &&  start_idx >= s.length()){
        results.push_back(sol);
        return ;
    }
    if(start_idx >= s.length() ) return;
    string sol_cp(sol);
    for(int i= 1; i<=min((int)s.length()-start_idx, 3); i++){
        string cur_num =  s.substr(start_idx, i);
        if(isValid(cur_num)){
            if(sol.empty()){
                sol = cur_num;
            }else{
                sol += string(".") + cur_num;
            }
            dfs(results, s, sol, start_idx+i, count+1);
            sol = sol_cp;
        }
    }
}

vector<string> restoreIpAddresses(string s){
    vector<string> results;
    if(s.length() <4 || s.length() >12) return results;
    string sol;
    dfs(results, s, sol, 0, 0);
    return results;
}


int main(int argc, char *argv[])
{
    string s("25525511135");
    vector<string> results = restoreIpAddresses(s);
    printVector(results);
    return 0;
}
