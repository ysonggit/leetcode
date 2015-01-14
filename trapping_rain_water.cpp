#include "utils.h"
#include <gtest/gtest.h>

using namespace std;

/*
idea: for each element in array, get the max left bar height and max right bar height
      the volume of water is computed below:
      there is a valid container at pos i iff
            A[i] < maxrightbar && A[i] < maxleftbar

      for a valid container
          volume =1 *( min(maxleftbar, maxrightbar) - A[i])

      sum up all container's volume
 */
int trap(int A[], int n) {
    if(A==NULL || n<=0) return 0;
    int total = 0;
    vector<int> maxleftbar(n,0);
    vector<int> maxrightbar(n,0);
    // get max left heights
    for(int i=0; i<n; i++){
        maxleftbar[i] = (i-1>=0) ? max(A[i], maxleftbar[i-1]) :  max(A[i],0);
    }
    // get max right heights
    for(int i=n-1; i>=0; i--){
        maxrightbar[i] = (i+1<n) ? max(A[i], maxrightbar[i+1]):  max(A[i],0);
    }
   
    // compute volume
    for(int i=0; i<n; i++){
        // check valid container
        if(A[i]<maxleftbar[i] && A[i]<maxrightbar[i]){
            // compute volumn
            total += min(maxleftbar[i], maxrightbar[i])-A[i];
        }
    }
    return total;
}

TEST(TrappingWater, One){
    int A[]={0,1,0,2,1,0,1,3,2,1,2,1};
    int res = 6;
    ASSERT_EQ(res, trap(A, 12));
}

TEST(TrappingWater, Two){
    int A[]={2,0,2};
    int res = 2;
    ASSERT_EQ(res, trap(A, 3));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

