#include <gtest/gtest.h>
#include "utils.h"
#include <bitset>

using namespace std;

/*
    idea : 
    unsigned int , no negative
    overflow? no, reverse 11111....11111  will get the same number
    the i-th bit (i=0..31) of input number is the (31-i)-th bit of output number

    get the k-th bit of an integer :
    http://stackoverflow.com/questions/2249731/how-to-get-bit-by-bit-data-from-a-integer-value-in-c
    int mask =  1 << k;
    int masked_n = n & mask;
    int thebit = masked_n >> k;
*/
uint32_t reverseBits(uint32_t n) {
    bitset<32> rev_n;
    for(int i=0; i<32; i++){
        int mask = 1 << i;
        int masked_n = n & mask;
        int thebit = masked_n >> i;
        rev_n[31-i] = thebit;
    }
    return rev_n.to_ulong();
}

TEST(testcase, I){
    uint32_t n = 43261596;
    uint32_t rev = 964176192;
    ASSERT_EQ(rev, reverseBits(n));
}

TEST(testcase, II){
    uint32_t n = UINT_MAX;
    uint32_t rev = UINT_MAX;
    ASSERT_EQ(rev, reverseBits(n));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}