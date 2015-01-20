#include "utils.h"
#include <gtest/gtest.h>

using namespace std;

/*
  idea:
  let each kid's rating be 1,0,2,3,1,4,3,0
  you can draw a bar chart 
  (similar to trapping rain water problem)
  two scans:
  1. scan from left, define array min_left[]
     min_left[i] means the minimum number of candies for kid i based on the left neighbor
  2. scan from right, define array min_right[]
     min_right[i] means the minimum number of candies for kid i based on the right neighbor
  3. for i^th kid, the min number of candies is max(min_left[i], min_right[i])
  the total number is sum of all min number of candies for each one

  note step 2 and 3 can be merged as one loop, I just use three loops, easy to understand
 */

int candy(vector<int> &ratings) {
    const int n = ratings.size();
    if(n==0) return 0;
    int min_left[n];
    min_left[0] = 1;
    for(int i=1; i<n; i++){
        min_left[i] = (ratings[i] > ratings[i-1]) ? min_left[i-1]+1 : 1;
    }
    int min_right[n];
    min_right[n-1] = 1;
    for(int i=n-2; i>=0; i--){
        min_right[i] = (ratings[i] > ratings[i+1]) ? min_right[i+1]+1 : 1;
    }
    int total = 0;
    for(int i=0; i<n; i++){
        total += max(min_left[i], min_right[i]);
    }
    return total;
}

TEST(Candy, I){
    vector<int> ratings={ 1,0,2,3,1,4,3,0};
    int res = 15;
    ASSERT_EQ(res, candy(ratings));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

