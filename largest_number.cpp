#include "utils.h"

using namespace std;

/*
  idea : convert each number to string
         define a comparator for each number-converted-string
         for example:
         (9, 89, 8, 81, 5, 80, 123, 86, 813)
         the desired order after comparison is:
         9
         89
         8
         86
         81
         813
         80
         5
         123
 */
struct GreaterComparator{
    bool operator() (string s1, string s2){
        return s1+s2>s2+s1;
    }
};

string largestNumber(vector<int> &num) {
    string largest("");
    if(num.size()==0) return largest;
    vector<string> num_str;
    for(int i : num){
        stringstream ss;
        ss<<i;
        num_str.push_back(ss.str()); 
    }
    sort(num_str.begin(), num_str.end(), GreaterComparator());
    for(string s : num_str){
        largest += s;
    }
    // special case: filter extra 0's
    while(*(largest.begin())=='0' && largest.size()>1){
        largest = largest.substr(1);
    } 
    
    return largest;
}


int main(int argc, char *argv[]){
    vector<int> num = {3,30,34,5,9};
    cout<<largestNumber(num)<<endl;
    vector<int> num1 = {9, 89, 8, 81, 5, 80, 123, 86, 813};
    cout<<largestNumber(num1)<<endl;
    vector<int> num2 = {0,0};
    cout<<largestNumber(num2)<<endl;
    return 0;
}

