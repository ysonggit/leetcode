#include <gtest/gtest.h>
#include "utils.h"

using namespace std;
/*
  Rotate an array of n elements to the right by k steps.
  For example, with n = 7 and k = 3,
  the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
  idea:
  move last to the first k times
  O(kn) time O(1) spaces
  make sure k <= n, when k==0 return , when k==n, reverse array
  how about k = 2n ?
  1 2 3 4 5 6 7
  move last to the first
  7 1 2 3 4 5 6
  move last to the first
  6 7 1 2 3 4 5
  move last to the first
  5 6 7 1 2 3 4

  869ms 
 */
/*
void rotate(int nums[], int n, int k) {
    if(k<=0) return;
    if(k>n) k = k % n;
    for(int i=0; i<k; i++){
        int last = nums[n-1];
        for(int j=n-1; j>0; j--){
            nums[j] = nums[j-1];
        }
        nums[0] = last;
    }
    }*/

/*
  promotion : move last k elements to the first k elements in place
  O(n) time O(n) space
  26ms
 */
void rotate(int nums[], int n, int k) {
    if(k<=0) return;
    if(k>n) k = k % n;
    vector<int> first_n_k(nums, nums+n-k);
    vector<int> last_k(nums+n-k, nums+n);
    for(int i=0; i<n; i++){
        if(i<k){
            nums[i] = last_k[i];
        }else{
            nums[i] = first_n_k[i-k];
        }
    }
}

TEST(Rotate, I){
    int nums[] ={1,2,3,4,5,6,7};
    int n= 7, k = 3;
    rotate(nums, n, k);
    for_each(nums, nums+n, [](int & i){cout<<i<<" ";});
    cout<<endl;
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



