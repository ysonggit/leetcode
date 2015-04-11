#include <gtest/gtest.h>
#include "utils.h"
using namespace std;

int singleNumber(int A[], int n) {
    if(n==0) return 0;
    int mask =A[0];
    for(int i=1; i<n; i++){
        mask = mask ^ A[i];
    }
    return mask;
}

TEST(SingleNumber, I){
    int A[] ={1,2,2,1,4,3,4};
    int res = 3;
    ASSERT_EQ(res, singleNumber(A, 7));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
