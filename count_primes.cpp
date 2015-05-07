#include <gtest/gtest.h>
#include "utils.h"
using namespace std;
// sieve of eratosthenes
int countPrimes(int n) {
    if(n<=1) return 0;
    vector<int> A(n, 1);
    for(int i=2; i<=(int)sqrt(n); i++){
        if(A[i]==1){
            for (int j=i*i; j<n; j += i){
                A[j] = 0;
            }
        }
    }
    int count = 0;
    for(int i=2; i<n; i++){
        if(A[i]==1) count++;
    }
    return count;
}

TEST(PRIME, I){
    int n = 30;
    int res = 10;
    ASSERT_EQ(res, countPrimes(n));
}

TEST(PRIME, II){
    int n = 3;
    int res = 1;
    ASSERT_EQ(res, countPrimes(n));
}

TEST(PRIME, III){
    int n = 2;
    int res = 0;
    ASSERT_EQ(res, countPrimes(n));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
