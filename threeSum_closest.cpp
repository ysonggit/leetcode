#include "utils.h"

using namespace std;

int threeSumClosest(vector<int> &num, int target) {
    if(num.size()==0)  return 0;
    sort(num.begin(), num.end());
    // minimize value of target - (num1 + num2 + num3)
    int min_diff = INT_MAX; 
    int best_sum = 0;
    for(int i=0; i<num.size(); i++){
        int num1 = num[i];
        // two sum
        int front = i+1;
        int back = num.size()-1;
        while(front < back){
            int num2 = num[front];
            int num3 = num[back];
            int sum = num1 + num2  + num3;
            if(sum == target) return target;
            int cur_diff = sum - target;
            if( abs(cur_diff) < min_diff ){
                min_diff = abs(cur_diff);
                best_sum = sum;
            }
            if(cur_diff > 0) {
                back--;
            }else{
                front++;
            }
        }
        
    }
    return best_sum;
}

int main(){
    int S[4] ={-1,2,1,-4};
    vector<int> num(S, S+sizeof(S)/sizeof(int));
    cout<<threeSumClosest(num, 1)<<endl;
    return 0;
}
