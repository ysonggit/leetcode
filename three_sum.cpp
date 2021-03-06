#include "utils.h"
using namespace std;


vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int> > results;
    if(num.size() <= 2) return results;
    std::sort(num.begin(), num.end());
    for(int i=0; i<num.size(); i++){
        int target = - num[i];
        // invoke twoSum
        int front = i+1; 
        int back = num.size()-1;
        while(front < back){
            int num1 = num[front];
            int num2 = num[back];
            int sum = num1 + num2;
            if(sum == target){
                vector<int> sol;
                sol.push_back(-target);
                sol.push_back(num1);
                sol.push_back(num2);
                results.push_back(sol);
                front++;
                back--;
                while(front<back && num[front] == num[front-1]) front++;
                while(front<back && num[back] == num[back+1]) back--;
            }else if(sum < target){
                front++;
            }else{
                back--;
            }
        }
        if(i+1<num.size()){
            while(num[i] == num[i+1]) i++;
        }
    }
    return results;
}

int main(){
    vector<int> num(3,0);
    vector<vector<int> > res = threeSum(num);
    print2DVector(res);
    vector<int> num1({-1, 0, 1, 2, -1, -4});
    vector<vector<int> > res1 = threeSum(num1);
    print2DVector(res1);

    return 0;
}
