#include "utils.h"
#include <gtest/gtest.h>
using namespace std;

/*
  Basic idea: use a hash map, O(n) time and O(n) extra space
  Optimized version: moore's voting algorithm O(n) time constant extra space
  http://www.geeksforgeeks.org/majority-element/
  The idea is that, since the majority element shows more than n/2 times
  so cancel it out with other elements, finally it will be kept 
 Moore's voting algorithm
 If the counter is 0, we set the current candidate to x and the counter to 1.
 If the counter is not 0, we increment or decrement the counter based on whether x is the current candidate.
*/

int majorityElement(vector<int> &num) {
    if(num.size()==0) return 0;
    int counts = 0;
    int candidate;
    for_each(num.begin(), num.end(), [&counts, &candidate](int x){
            if(counts==0) {
                candidate = x;
                counts = 1;
            }else{
                if(x == candidate) counts++;
                else counts--;
            }
        });
    return candidate;
}

TEST(FindMajority, I){
    vector<int> num{2};
    ASSERT_EQ(2, majorityElement(num));
}

TEST(FindMajority, II){
    vector<int> num{2, 2, 3, 5, 2, 2, 6};
    ASSERT_EQ(2, majorityElement(num));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

