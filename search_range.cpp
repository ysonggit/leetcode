#include "utils.h"

using namespace std;
// return index of target 
int binarySearch(int A[], int start_idx, int end_idx, int target){
    if(start_idx > end_idx) return -1;
    int mid_idx = (start_idx + end_idx)/2;
    if(A[mid_idx]== target) return mid_idx;
    if(A[mid_idx]>target ) return binarySearch(A, start_idx, mid_idx-1, target);
    return binarySearch(A, mid_idx+1, end_idx, target);
}

vector<int> searchRange(int A[], int n, int target) {
    vector<int> range(2, -1);
    if(n<=0) return range;
    int idx = binarySearch(A, 0, n-1, target);
    if(idx<0) return range;
    int left_idx = idx, right_idx = idx;
    while(left_idx>0){
        if(A[left_idx-1]!=target){
            break;
        }
        left_idx--;
    }
    while(right_idx<n-1){
        if(A[right_idx+1] != target){
            break;
        }
        right_idx++;
    }
    range[0]=left_idx;
    range[1]=right_idx;
    return range;
}


int main(){
    int A[6]={
        5,7,7,8,8,10
    };
    vector<int> range = searchRange(A, 6, 8);
    printVector(range);
    return 0;
}
