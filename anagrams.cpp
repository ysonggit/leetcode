#include "utils.h"

using namespace std;

/*
  idea : for each string, sort the letters
         hash the sorted string, use the multimap, the values are the indices of anagrams
         if each string is not very long, just use sort()
*/

vector<string> anagrams(vector<string> &strs) {
    vector<string> all_anagrams;
    if(strs.size()==0) return all_anagrams;
    unordered_map<string, int> str_count;
    unordered_map<string, string> str_cache;
    set<string> duplicated_keys;
    for(int i=0; i<strs.size(); i++){
        string key = strs[i];
        std::sort(key.begin(), key.end() );
        if(str_count.find(key) == str_count.end()){
            str_count[key]=1;
            str_cache[key]=strs[i];
        }else{
            str_count[key]++;
            if(duplicated_keys.find(key) == duplicated_keys.end()){
                duplicated_keys.insert(key);
            }
            all_anagrams.push_back(strs[i]);
        }
    }
    // recall that the first time shown anagrams have not been pushed to results yet
    for(auto iter = duplicated_keys.begin(); iter != duplicated_keys.end(); ++iter){
        all_anagrams.push_back(str_cache[*iter]);
    }

    return all_anagrams;
}

int main(int argc, char *argv[])
{
    vector<string> strs {"ray","cod","abe","ned","arc","jar","owl","pop","paw","sky","yup","fed","jul","woo","ado","why","ben","mys","den","dem","fat","you","eon","sui","oct","asp","ago","lea","sow","hus","fee","yup","eve","red","flo","ids","tic","pup","hag","ito","zoo"};
    vector<string> res = anagrams(strs);
    printVector(res);
    vector<string> str2{"", ""};
    vector<string> res2 = anagrams(str2);
    printVector(res2);
    return 0;
}


