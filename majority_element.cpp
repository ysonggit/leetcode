#include "utils.h"
#include <gtest/gtest.h>
using namespace std;

/* Basic idea: use a hash map, O(n) time and O(n) extra space
   Optimized version: moore's voting algorithm O(n) time constant extra space
   http://www.geeksforgeeks.org/majority-element/
   The idea is that, since the majority element shows more than n/2 times
   so cancel it out with other elements, finally it will be kept

   initialize idx and count of the majority element
   maj_idx = 0, count = 1

   for each i = 1 ... n-1
       if A[maj_idx] == A[i]
           count++
       else
           count--
       if count == 0
          maj_idx = i
          count = 1
   return A[maj_idx]
 */

int majorityElement(vector<int> &num){
    int maj_idx = 0;
    int count = 1;
    for(int i=1; i<num.size(); i++){
        if(num[maj_idx]==num[i]){
            count++;
        }else{
            count--;
        }
        if(count==0){
            maj_idx = i;
            count = 1;
        }
    }
    return num[maj_idx];
}

TEST(FindMajority, TestCase){
    int A[] = {2, 2, 3, 5, 2, 2, 6};
    vector<int> num(A, A+sizeof(A)/sizeof(*A));
    ASSERT_EQ(2, majorityElement(num));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

