#include <gtest/gtest.h>
#include "utils.h"
using namespace std;

/*
 Hamming weight problem O(1)
 idea:
 1. naively check each bit one-by-one
    to get the k-th bit:
    int mask = 1<<k
    int mask_n = mask & n
    int kthbit = mask_n>>k
    18ms

 2. Bitwise AND x with x-1 to zero the "1" in the least significant bit (not rightmost)
    10ms
    int hammingWeight(uint32_t n){
        int num_of_ones = 0;
        while(n){
            num_of_ones++;
            n = n & (n-1);
        }
        return num_of_ones;
    }
 */
/*
   3. Popcount (divide and conquer)
   http://en.wikipedia.org/wiki/Hamming_weight
   http://stackoverflow.com/questions/15233121/calculating-hamming-weight-in-o1
   9ms
   for example : given 8-bit binary : n = 10001011
   first count of 1s of each 2 bit
   10001011
  &01010101
  ----------
   00000001
  +
   01000101
  &01010101
  ----------
   01000101

  = 01 00 01 10 ==> means : for the original n = 10001011
   ---|--|--|--
    |  |  |  |_ there are 10(2) ONEs in the leftmost two bits
    |  |  |
    |  |  |_ there is 01(1) ONE in these two bits
    |  |
    |  |_ there is 00 ONE in these two bits
    |
    |_ there is 01 (1) ONE in the rightmost 2 bits

  01000110
 &00110011
 ----------
  00000010
 +
  00010001
 &00110011
 ----------
  00010001

 =
  0001 0011
  ----|----
   |    |_ there are 0011(3) ONEs in the leftmost four bits
   |
   |_ there is 0001(1) ONE in the rightmost four bits

  00010011
 &00001111
 ---------
  00000011
 +
  00000001
 &00001111
 ---------
  00000001
 =
  00000100 ==> there are 00000100(4) ONEs in the original number n 
*/
const uint32_t m1 = 0x55555555; //0101 ...
const uint32_t m2 = 0x33333333; //0011 ...
const uint32_t m4 = 0x0f0f0f0f; //00001111 ...
const uint32_t m8 = 0x00ff00ff; //00000000 11111111
const uint32_t m16 = 0x0000ffff;//16 zeros 16 ones
int hammingWeight(uint32_t n){
    n = (n&m1)+((n>>1) & m1); //put count of each  2 bits into those  2 bits
    n = (n&m2)+((n>>2) & m2); //put count of each  4 bits into those  4 bits 
    n = (n&m4)+((n>>4) & m4); //put count of each  8 bits into those  8 bits 
    n = (n&m8)+((n>>8) & m8); //put count of each 16 bits into those  16 bits 
    n = (n&m16)+((n>>16) & m16); //put count of each 32 bits into those  32 bits 
    return n;
}

TEST(HammingWeight, I){
    uint32_t n = 0;
    int res = 0;
    ASSERT_EQ(res, hammingWeight(n));
}

TEST(HammingWeight, II){
    uint32_t n = 1;
    int res = 1;
    ASSERT_EQ(res, hammingWeight(n));
}

TEST(HammingWeight, III){
    uint32_t n = UINT_MAX;
    int res = 32;
    ASSERT_EQ(res, hammingWeight(n));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}