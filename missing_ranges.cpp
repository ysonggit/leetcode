#include "utils.h"

using namespace std;

string getRange(int start_num, int end_num){
    stringstream ss;
    ss<<start_num;
    if(start_num==end_num) return ss.str();
    ss<<"->"<<end_num;
    return ss.str();
}

vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
    vector<string> results;
    if(n==0){
        results.push_back(getRange(lower, upper));
        return results;
    }
    vector<int> segments;
    segments.push_back(lower);
    for(int i=0; i<n; i++){
        if(A[i]>=lower && A[i]<=upper){
            segments.push_back(A[i]);
        }            
    }
    segments.push_back(upper);
    int m = segments.size()-1;
    for(int i=0; i<m; i++){
        // lower and upper numbers should be included
        int start_num = (i==0)? segments[i]-1 : segments[i];
        int end_num = (i==m-1)? segments[i+1]+1: segments[i+1];
        //cout<<"start: "<<start_num<<"  end: "<<end_num<<endl;  
        if(end_num - start_num >1){
            results.push_back(getRange(++start_num,--end_num));
        }
    }
    return results;
}

int main(){
    int A[5] ={
        0,1,3,50,75
    };
    vector<string> results = findMissingRanges(A, 5, 0, 99);
    printVector(results);
    int B[]={
        
    };
    vector<string> res = findMissingRanges(B, 0, -3, -1);
    printVector(res);

    int C[]={
        -1
    };
    vector<string> res2 = findMissingRanges(C, 1, -2, -1);
    printVector(res2);

    int D[]={
        
    };
    vector<string> res3 = findMissingRanges(D, 0, 1, 1);
    printVector(res3);
    return 0;
}
