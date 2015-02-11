#include "utils.h"
#include <gtest/gtest.h>

using namespace std;
/*
  idea
  1. using stringstream : convert int to string 
  reverse string and compare if equal to the original string
  181 ms
  2. compare the highest bit with the lowest bit
  n = 234565432
  finding the highest bit and the lowest bit is actually finding 
  the divider d such that n / d  = highest bit and n % 10 = lowest bit
  3456543
  |
  45654
  |
  565
  |
  6

  100021
  |
  2 (note here 2 is actually the lowest bit, 0 is the highest bit)
  
  be careful of negative numbers, any negative number is not palindrome
  138ms
*/

bool isPalindrome(int x){
    if (x < 0 ) return false;
    int d = 1;
    while(x / d >= 10) d *= 10;
    while(x > 0){
        int highest_bit = x / d;
        int lowest_bit = x % 10;
        if(highest_bit != lowest_bit ) return false;
        //cout<<"x = "<<x<<": higest "<<highest_bit<<" , lowest "<<lowest_bit<<endl;
        // remove highest bit and lowest bit
        x -= (highest_bit* d + lowest_bit); 
        x /= 10;
        d /= 100;
        // cout<<" now check x = "<<x<<", d = "<<d<<endl;
    }
    return true;
}

TEST(Palindrome, I){
    int x = 234565432;
    bool res=true;
    ASSERT_EQ(res, isPalindrome(x));
}

TEST(Palindrome, II){
    int x = 23455432;
    bool res=true;
    ASSERT_EQ(res, isPalindrome(x));
}

TEST(Palindrome, III){
    int x = 2345675432;
    bool res=false;
    ASSERT_EQ(res, isPalindrome(x));
}

TEST(Palindrome, IV){
    int x = 100021;
    bool res=false;
    ASSERT_EQ(res, isPalindrome(x));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


