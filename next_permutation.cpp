#include "utils.h"

using namespace std;

/*
  given a permutation
  1. find the larget index k : a[k] < a[k+1], if no such k, then return lowest possible order
  2. find the larget index l >k, such that a[k] < a[l]
  3. swap value of a[k] with a[l]
  4. reverse seq from a[k+1] up to and including the final element a[n]
 */

void nextPermutation(vector<int> &num) {
    int n = num.size();
    // 1.  find the larget k
    int k = -1;
    for(int i=0; i<n-1; i++){
        if(num[i] < num[i+1]){
            k = i;
        }
    }
    if(k<0) {
        // return lowest possible order
        sort(num.begin(), num.end());
        return ;
    }
    // 2.  find the larget l
    int l;
    for(int i=k+1; i<n; i++){
        if(num[i] > num[k]) {
            l = i;
        }
    }
    // 3. swap 
    std::swap(num[k], num[l]);
    // 4. reverse seq from k+1
    reverse(num.begin()+k+1, num.end());
    
}

int main(){
    vector<int> num1(3);
    for(int i=1; i<=3; i++){
        num1[i-1] = i;
    }
    nextPermutation(num1);
    printVector(num1);

    vector<int> num2;
    for(int i=3; i>0; i--){
        num2.push_back(i);
    }
    nextPermutation(num2);
    printVector(num2);

    vector<int> num3;
    num3.push_back(1);
    num3.push_back(1);
    num3.push_back(5);
    nextPermutation(num3);
    printVector(num3);
    return 0;
}
