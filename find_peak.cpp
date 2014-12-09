#include "utils.h"
#include <climits>
using namespace std;
// question : peak is not necessarily unique
//            how about given an empty array?
//            how about overflow?
// return the index of the peak element
int binarySearch(const vector<int> & num, int start_idx, int end_idx){
    int mid_idx = (start_idx + end_idx)/2;
    // be careful of mid_idx
    int left_val = (mid_idx - 1 >=0) ? num[mid_idx-1] : INT_MIN;
    int right_val = (mid_idx + 1 >= num.size()) ? INT_MIN : num[mid_idx+1];
    int cur_val = num[mid_idx];
    if((mid_idx ==0 && cur_val >= right_val ) || (mid_idx == num.size()-1 && cur_val >= left_val)) return mid_idx;
    if(cur_val > left_val && cur_val > right_val) return mid_idx;

    if(cur_val < left_val){
        // peak must be on the left
        return binarySearch(num, start_idx, mid_idx-1);
    }
    if(cur_val < right_val){
        // peak must be on the right
        return binarySearch(num, mid_idx+1, end_idx);
    }
    return -1;
}


int findPeakElement(const vector<int> &num) {
    if(num.size()==0) return -1;
    return binarySearch(num, 0, num.size()-1);
}


int main(){
    vector<int> num1; // return 2
    for(int i=1; i<4; i++){
        num1.push_back(i);
    }
    num1.push_back(1);
    vector<int> num2; // 1,2 return 1
    for(int i=1; i<3; i++){
        num2.push_back(i);        
    }
    vector<int> num3; // 5,4,3,2,1,0 return 0
    for(int i=5; i>=0; i--){
        num3.push_back(i);        
    }
    
    cout<<findPeakElement(num1)<<endl;
    cout<<findPeakElement(num2)<<endl;
    cout<<findPeakElement(num3)<<endl;
    return 0;
}
