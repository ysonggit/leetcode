#include "utils.h"

using namespace std;
/*
  idea: sliding window
  suppose each word in given list has length k
  first create a hashmap, for each entry the key is each word, the value is initialized as the
  count of the word shown in the dictionary
  the tricky part is that one word may show multiple times in given dictionary
  
  if found a word in string, reduce the corresponding value in map
*/

vector<int> findSubstring(string S, vector<string> &L) {
    vector<int> results;
    int word_len = L[0].length();
    int concat_len = word_len * L.size();
    int n = S.length();
    if(n < concat_len) return results;
    unordered_map<string, int> dict;
    for(string w : L) ++dict[w];
    string cur;
    for(auto i= 0; i<= n- concat_len; i++){
        unordered_map<string, int> words(dict);
        for(auto j=i; j != concat_len + i ; j+=word_len){
            cur = S.substr(j, word_len);
            auto pos = words.find(cur);
            if(pos == words.end() || pos->second == 0 ) break;
            if(--pos->second == 0 ) {
                words.erase(pos);
            }
    
            if(words.size()==0) {
                results.push_back(i);
            }
        }
    }
    return results;
}

int main(int argc, char *argv[]){
    vector<string> L = {"bar", "foo"};
    string s("barfoothefoobarman");
    vector<int> actual = findSubstring(s, L);
    printVector(actual);
    vector<string> L1 = {"a", "b", "a"}; // one word show multiple times
    string s1("abababab");
    vector<int> actual1 = findSubstring(s1, L1);
    printVector(actual1);
    return 0;
}


