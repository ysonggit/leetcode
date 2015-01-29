#include "utils.h"

using namespace std;

/*
  idea: Hash Map (multimap) O(n^2) time, O(n^2) space
  convert this problem to a double 2Sum problem
  create a hashmap: key is the sum of two elements,
                    value is a pair<int,int>, which contains the indices of two elements whose sum == key

  then, the task is to solve another 2sum problem among the keys of the map
  time limit exceeded
  
void showMapEntry(std::pair<int, std::pair<int, int> > entry){
    cout<<entry.first<<" : {"<<(entry.second).first<<", "<<(entry.second).second<<"}\n";
}

vector<vector<int> > fourSum(vector<int> & num, int target){
    vector<vector<int> > results;
    int n = num.size();
    if (n<4) return results;
    sort(num.begin(), num.end());
    unordered_multimap<int, pair<int, int> > sum_pairs;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int sum_ij = num[i] + num[j];
            sum_pairs.insert(make_pair(sum_ij, make_pair(i,j)));
        }
    }
    //for_each(sum_pairs.begin(), sum_pairs.end(), showMapEntry);
    // do two sum on the map's entries
    for(auto it = sum_pairs.begin(); it != sum_pairs.end(); ++it){
        int num1 = it->first;
        // num1 = num[idx1] + num[idx2]
        int idx1 = it->second.first;  // idx1 != idx2 for sure
        int idx2 = it->second.second; 
        int num2 = target - num1;
        // range_iter is a pair of iterators, indicates the bounds of a range such that
        // in the map, all elements have a key equal to num2
        auto range_iter = sum_pairs.equal_range(num2);
        for(auto itt = range_iter.first; itt != range_iter.second; ++itt){
            //num2 = num[idx3] + num[idx4]
            int idx3 = itt->second.first; // idx3 != idx4 for sure
            int idx4 = itt->second.second;
            if(idx1 != idx3 && idx2 != idx4 && idx1 != idx4 && idx2 != idx3){
                vector<int> quadruplet = {num[idx1], num[idx2], num[idx3], num[idx4]};
                sort(quadruplet.begin(), quadruplet.end());
                results.push_back(quadruplet);
            }
        }
    }
    // so far results may contain duplicates, caused by num1 = num2 case
    // std::unique in <algorithm> remove all but the first element
    // from every consecutive group of equivalent elements in the range [first,last).
    // after that, the size of container does not change
    results.erase(std::unique(results.begin(), results.end()), results.end());
    return results;
    }*/
/*
  O(n^3) method
 */
vector<vector<int> > fourSum(vector<int> & num, int target){
    vector<vector<int> > results;
    int n = num.size();
    if (n<4) return results;
    sort(num.begin(), num.end());
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int sum_ij = num[i] + num[j];
            int two_sum  = target - sum_ij;
            int front = j+1;
            int back = n-1;
            while(front<back){
                int num1 = num[front];
                int num2 = num[back];
                if(num1+num2==two_sum){
                    vector<int> quadruplet = {num[i], num[j], num1, num2};
                    results.push_back(quadruplet);
                    front++;
                    back--;
                    while(num[front]==num[front-1]) front++;
                    while(num[back]== num[back+1] ) back--;
                }
                else if(num1+num2<two_sum){
                    front++;
                }else{
                    back--;
                }
            }
            while(j+1<n && num[j]==num[j+1]) j++;
        }
        while(i+1<n-1 && num[i] == num[i+1]) i++;
    }
    return results;
}

int main(int argc, char *argv[]){
    vector<int> num = {1, 0 , -1, 0, -2, 2};
    int target = 0;
    vector<vector<int> > results = fourSum(num, target);
    /*
      (-1,  0, 0, 1)
      (-2, -1, 1, 2)
      (-2,  0, 0, 2)
     */
    print2DVector(results);
    return 0;
}


