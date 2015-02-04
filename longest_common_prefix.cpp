#include "utils.h"

using namespace std;

string longestCommonPrefix(vector<string> &strs) {
    string prefix;
    int n = strs.size();
    if(n==0) return prefix;
    for(int i=0; i<strs[0].length(); i++){
        for(int j=1; j<n; j++){
            if(strs[j][i] != strs[0][i] || strs[j].length()==i ){
                return strs[0].substr(0, i);
            }
        }
    }
    return strs[0]; // corner case: contains only one string
}

int main(int argc, char *argv[]){
    vector<string> strs={"hello","hey", "hell", "helicopter", "he"};
    cout<<longestCommonPrefix(strs)<<endl;
    return 0;
}


