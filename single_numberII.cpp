#include <gtest/gtest.h>
#include "utils.h"
using namespace std;

int singleNumber(int A[], int n) {
    vector<int> digits(32, 0);
    for(int i =0; i<n; i++){
        // get k-th bit of number i
        for(int k=0; k<32; k++){
            digits[k] += (A[i]>>k)&1;
        }
    }
    int num  = 0;
    for(int j =0 ; j< digits.size(); j++){
        num += (digits[j] % 3)<<j;
    }
    return num;
}

TEST(SingleNumber, I){
    int A[] ={1,1,2,2,1,2,3};
    int res = 3;
    ASSERT_EQ(res, singleNumber(A, 7));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
