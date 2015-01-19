#include "utils.h"
#include <unordered_set>

using namespace std;
/*
  DFS
   for example s="catsanddog"
   f[10] ={false, false, true, true, false, false, true, false, false, true}
 */


vector<string> wordBreak(string s, unordered_set<string> & dict){
    vector<string> results;
    if(s.empty()) return results;
    int n = s.length();

    // printVector(f);
    //print2DVector(wd);
    return results;
}

int main(int argc, char *argv[]){
    string s("catsanddog");
    unordered_set<string> dict ={"cat", "cats", "sand", "and", "dog"};
    wordBreak(s, dict);
    return 0;
}

