#include "utils.h"
#include <gtest/gtest.h>
using namespace std;
struct Bucket{
    Bucket(){
        min_val = INT_MAX;
        max_val = INT_MIN;
        count = 0;
    }
    int min_val;
    int max_val;
    int count;
};
// https://algnotes.wordpress.com/2012/07/22/the-maximum-gap-problem/
// linear time solution
int maximumGap(vector<int> & num){
    int n = num.size();
    int max_gap = 0;
    if(n < 2) return max_gap;
    // 1. find max and min
    int max_num = *max_element(num.begin(), num.end());
    int min_num = *min_element(num.begin(), num.end());
    // 2. divide the interval [min, max] into n-1
    double delta = (double) (max_num - min_num)/(n-1); // BE CAREFULL! convert int to (double)
    // 3. fill buckets
    // use array instead of vector can speed up computations
    Bucket *buckets = new Bucket[n-1];  
    for(int i=0; i<n; i++){
        if(num[i]!= max_num && num[i]!= min_num){
            int k = (int) floor((num[i]-min_num)/delta);
            // num[i] should be in buckets[k]
            buckets[k].min_val = min(buckets[k].min_val, num[i]);
            buckets[k].max_val = max(buckets[k].max_val, num[i]);
            buckets[k].count++;
        }
    }
    // 4. construct list L of all ordered minima and maxima
    vector<int> L;
    L.push_back(min_num);
    for(int k=0; k<n-1; k++){
        if(buckets[k].count>1){
            L.push_back(buckets[k].min_val);
            L.push_back(buckets[k].max_val);
        }
        if(buckets[k].count==1){
            L.push_back(buckets[k].min_val);
        }
    }
    L.push_back(max_num);
    for(int i=0; i<L.size()-1; i++){
        max_gap = max(max_gap, L[i+1] - L[i]);
    }
    delete [] buckets;
    buckets = NULL; // clear to prevent using invalid memory reference
    return max_gap;
}

TEST(MaxGap, One){
    int A[] = {3,7,2,5,6,4,9,1,2,2,10};
    vector<int> num(A, A+sizeof(A)/sizeof(*A));
    int res = 2;
    ASSERT_EQ(res, maximumGap(num));
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


