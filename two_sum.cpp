#include "utils.h"

using namespace std;
/*
 O(nlogn) time, O(n) space
  
vector<int> twoSum(vector<int> & numbers, int target){
    vector<int> result;
    int n = numbers.size();
    if(n<2) return result;
    unordered_multimap<int, int> val_idx;
    for(int i=0; i<n; i++){
        val_idx.insert(make_pair(numbers[i], i)); //use val_idx[numbers[i]]=i will replace existed entry
    }
    sort(numbers.begin(), numbers.end());
    int front = 0, back = n-1;
    while(front<back){
        int num1 = numbers[front];
        int num2 = numbers[back];
        if(num1 + num2 ==target){
            auto range_iter = val_idx.equal_range(num1);
            for(auto it = range_iter.first; it!= range_iter.second; ++it){
                result.push_back(it->second+1);
            }
            if(num1 != num2){
                range_iter = val_idx.equal_range(num2);
                for(auto it = range_iter.first; it!= range_iter.second; ++it){
                    result.push_back(it->second+1);
                }
            }
            front++;
            back--;
            //while(numbers[front]==numbers[front-1]) front++; // remove duplicates
            //while(numbers[back]==numbers[back-1]) back--;
        }else if(num1+num2<target){
            front++;
        }else{
            back--;
        }
    }
    sort(result.begin(), result.end());
    return result;
    }*/

/*
  O(nlogn) time, O(n) space
 */
vector<int> twoSum(vector<int> & numbers, int target){
    vector<int> result;
    int n = numbers.size();
    if(n<2) return result;
    unordered_multimap<int, int> val_idx;
    for(int i=0; i<n; i++){
        val_idx.insert(make_pair(numbers[i], i)); //use val_idx[numbers[i]]=i will replace existed entry
    }

    for(auto num1_iter = val_idx.begin(); num1_iter!=val_idx.end(); ++num1_iter){
        int num1 = num1_iter->first;
        int num2 = target - num1;
        if(result.size()==2) break;
        if(num1 == num2){
            auto range_iter = val_idx.equal_range(num2); //O(logN) time
            if(distance(range_iter.first, range_iter.second) != 1){
                // make sure these two equal numbers are not the same one
                // test case {1,2,3} target is 4
                // we want result to be indices of 1 and 3 instead of twice of 2
                for(auto it = range_iter.first; it!= range_iter.second; ++it){
                    result.push_back(it->second+1);
                }
            }
        }else{
            auto num2_iter = val_idx.find(num2);
            if(num2_iter != val_idx.end()){
                result.push_back(num1_iter->second+1);
                result.push_back(num2_iter->second+1);
            }
        }
    }
    sort(result.begin(), result.end()); // O(1) time since always 2 elements 
    return result;
}

int main(int argc, char *argv[])
{
    vector<int> numbers={2,7,11,15};
    int target = 9;
    vector<int> result = twoSum(numbers, target);
    printVector(result);
    vector<int> numbers1={0,4,1,0};
    int target1 = 0;
    vector<int> result1 = twoSum(numbers1, target1);
    printVector(result1);
    vector<int> numbers2= {1,2,3};
    int target2 = 4;
    vector<int> result2 = twoSum(numbers2, target2);
    printVector(result2);
    return 0;
}
