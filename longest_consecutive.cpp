#include "utils.h"

using namespace  std;

/*
  Longest Increasing Subsequence:
  L[i] : Longest Incresing Subseq ends with D[i]
  L[0] = {D[0]}
  L[i] = max(L[j] | j<i, D[j] < D[i]) + D[i]
  DP solution takes O(N^2) time:

  Different from LIS, which preserves the original sequence order
  
  O(n) solution requires extra data structure: HashMap (Unordered Map)
  http://yucoding.blogspot.com/2013/05/leetcode-question-129-longest.html

  1. insert every element into map
  2. iterate the array, for each element, lookup its nearby elements by -1 and +1
     update the length, update max_length

  Question: duplicates contained?
 */

int longestConsecutive(vector<int> &num) {
    if(num.size()==0) return 0;
    // use a map of (value, index)
    std::unordered_map<int, int> hash;
    for(int i =0; i<num.size(); i++){
        hash[num[i]] = i;
    }

    int max_length= 1;
    for(int i=0; i<num.size(); i++){
        int cur = num[i];
        int cur_length = 1;
        hash.erase(cur);
        int next = cur+1;
        int prev = cur-1;
        while(hash.find(next) != hash.end()){
            cur_length++;
            hash.erase(next);
            next++;
        }
        
        while(hash.find(prev) != hash.end()){
            cur_length++;
            hash.erase(prev);
            prev--;
        }
        if(cur_length> max_length){
            max_length = cur_length;
        }
    }
    return max_length;
}

int lisDP(vector<int> & D){
    vector<vector<int> > L (D.size());
    L[0].push_back(D[0]);
    //L[i] = max(L[j] | j<i, D[j] < D[i]) + D[i]
    int max_length = L[0].size();
    for(int i=1; i<D.size(); i++){
        for(int j=0; j<i; j++){
            if(D[j] < D[i] && L[i].size()<L[j].size()+1){
                L[i] = L[j];
            }
        }
        L[i].push_back(D[i]);
        if(L[i].size() < max_length){
            max_length = L[i].size();
        }
    }
    return max_length;
}

int main(){
    int A[] = {
        100,4,200,1,3,2
    };
    vector<int> num(A, A+sizeof(A)/sizeof(int));
    cout<<longestConsecutive(num)<<endl;
    cout<<lisDP(num)<<endl;
    return 0;
}
