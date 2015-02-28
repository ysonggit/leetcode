#include "utils.h"
#include <gtest/gtest.h>

using namespace std;

string getRange(int start_num, int end_num){
    stringstream ss;
    ss<<start_num;
    if(start_num==end_num) return ss.str();
    ss<<"->"<<end_num;
    return ss.str();
}
/*
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
    }*/
/*
  Given a sorted integer array where the range of elements are [lower, upper] inclusive,
  return its missing ranges.

  For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99,
  return ["2", "4->49", "51->74", "76->99"].

  tip: add a lower bound (first element of array -1 ) and upper bound (last element of array + 1)
  corner case : empty array ? array with one element?
  {}  lower -2, upper -1
  what should return ?  -2 -> -1
  {1} lower -2, upper -1
  what should return ? -2 -> 0
  adding lower bound and upper bound so array becomes -3, 0, 1, thus, return ranges -2 -> 0

*/
vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
    vector<string> ranges;
    int prev = lower - 1;
    for(int i=0; i<=n; i++){
        int cur = (i==n) ? upper + 1 : A[i];
        if(cur- prev >= 2){
            ranges.push_back(getRange(prev+1, cur-1));
        }
        prev = cur;
    }
    return ranges;
}

TEST(MissingRanges, I){
    int A[] = {0,1,3,50,75};
    int n = 5;
    int lower = 0;
    int upper = 99;
    vector<string> results = findMissingRanges(A, n, lower, upper);
    printVector(results);
}

TEST(MissingRanges, II){
    int A[] = {};
    int n = 0;
    int lower = -2;
    int upper = -1;
    vector<string> results = findMissingRanges(A, n, lower, upper);
    printVector(results);
}

TEST(MissingRanges, III){
    int A[] = {1};
    int n = 1;
    int lower = -2;
    int upper = -1;
    vector<string> results = findMissingRanges(A, n, lower, upper);
    printVector(results);
}

TEST(MissingRanges, IV){
    int A[] = {};
    int n = 0;
    int lower = 1;
    int upper = 1;
    vector<string> results = findMissingRanges(A, n, lower, upper);
    printVector(results);
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


