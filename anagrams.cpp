#include "utils.h"

using namespace std;

/*
  idea : for each string, sort the letters
         hash the sorted string, use the multimap, the values are the indices of anagrams
         if each string is not very long, just use sort()
*/

vector<string> anagrams(vector<string> &strs) {
   vector<string> res;
  if(strs.empty()) return res;
  unordered_map<string, vector<string> > anagram_group;
  for(string s : strs){
    string key = s;
    sort(key.begin(), key.end());
    anagram_group[key].push_back(s);
  }
  for(auto it = anagram_group.begin(); it!= anagram_group.end(); ++it){
    if(it->second.size()>1){
      res.insert(res.end(), it->second.begin(), it->second.end());
    }
  }
  return res;
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


