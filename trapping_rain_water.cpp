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
/*
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
            // compute volume
            total += min(maxleftbar[i], maxrightbar[i])-A[i];
        }
    }
    return total;
    }*/

/*
  idea : use stack to store the indices of bars, scan once
  if current bar height is smaller than the top of stack, push
  else, pop up the top until stack is empty or top is greater than current one
  while popping up, add up the volume and update the max vol
  then push current bar height to stack
  example:
  [0,1,0,2,1,0,1,3,2,1,2,1]
  4|
  3|              _
  2|      _      | |_   _
  1|  _  | |_   _| | |_| |_
  0|_|_|_|_|_|_|_|_|_|_|_|_|

  i=0, push 0, stack: 0
  i=1, pop stack and push 1, maxVol = 0, stack : 1
  i=2, push 2, stack : 2, 1
  i=3, pop stack, maxVol = 1, push 3, stack : 3
  i=4, push 4, stack : 4, 3
  i=5, push 5, stack : 5, 4, 3
  i=6, pop stack, maxVol = 2, push 6, stack : 6, 4, 3
  i=7, pop stack, maxVol = 5, push 7, stack : 7
  i=8, push 8, stack : 8, 7
  i=9, push 9, stack : 9, 8, 7
  i=10, pop stack, maxVol = 6, push 10, stack : 10, 8, 7
  i=11, push 11
  done

int trap(int A[], int n){
    if(A==NULL || n<=1) return 0;
    stack<int> bars_left;
    int max_volume = 0;
    // trick: pass by all leading 0 height bars
    int i=0;
    while(A[i]==0) i++;
    for(; i<n; i++){
        int cur_bar_height = A[i];
        // keep on pop until stack is empty or top is greater
        while(! bars_left.empty() && cur_bar_height >= A[bars_left.top()] ){
            int popped_bar = bars_left.top();
            bars_left.pop();
            if(bars_left.empty()) break;
            // the width should be i - bar_left.top - 1 not i-bar_left.top+1
            max_volume += (i- bars_left.top() -1) * (min(cur_bar_height, A[bars_left.top()])-A[popped_bar]);
        }
        bars_left.push(i);
    }
    return max_volume;
}*/
int trap(vector<int>& heights) {
      int n = heights.size();
      if(n<2) return 0;
      vector<int> maxleftbars(n, 0);// maxleftbars[i]: the max bar on the left side of pos i
      vector<int> maxrightbars(n, 0); // maxrightbars[i]: the max bar on the right side of pos i
      for(int i=1; i<n; i++){
            maxleftbars[i] = max(maxleftbars[i-1], heights[i-1]); // mistake : heights[i]
      }
      for(int i=n-2; i>=0; i--){
            maxrightbars[i] = max(maxrightbars[i+1], heights[i+1]); // mistake : heights[i]
      }
      int vol = 0;
      for(int i=0; i<n; i++){
            int cur_bar = heights[i];
            int min_bar = min(maxleftbars[i], maxrightbars[i]);
            if(cur_bar >= min_bar) continue;
            vol += (min_bar - cur_bar);
      }
      return vol;
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

