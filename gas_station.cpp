#include "utils.h"
#include <gtest/gtest.h>

using namespace std;

/*
  for gas station i, compute the remaining gas res[i] := gas[i] - cost[i] to the station i+1
  for i = 0... n-1
      total += res[i]

  if total[0...n-1] < 0 return -1
  else
     suppose i is the starting station from where the car can complete a circle to i-1
     then, sum[i...n-1] > 0
     Hence, maintains a local sum of [start_pos, cur_pos]
     if(sum of [start_pos, cur_pos] < 0) // no solution exists before cur_pos
        sum = 0
        start_pos = cur_pos + 1

  question: is starting position always unique?
*/

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    // assume gas and cost have same size
    const int n = gas.size();
    int total= 0, sum=0, start_pos=0;
    int res[n];
    for(int i=0; i<n; i++){
        res[i] =  gas[i] - cost[i];
        total += res[i];
        sum += res[i];
        if(sum <0){
            start_pos = i+1;
            sum = 0;
        }
    }
    return (total<0) ? -1 : start_pos;
}

TEST(GasStation, One){
    vector<int> gas ={4};
    vector<int> cost={5};
    int res = -1;
    ASSERT_EQ(res, canCompleteCircuit(gas, cost));
}

TEST(GasStation, Two){
    vector<int> gas ={2,4};
    vector<int> cost={3,4};
    int res = -1;
    ASSERT_EQ(res, canCompleteCircuit(gas, cost));
}

TEST(GasStation, Three){
    vector<int> gas ={3,6,7,2,8,4,4};
    vector<int> cost={4,2,3,5,9,6,4};
    int res = 1;
    ASSERT_EQ(res, canCompleteCircuit(gas, cost));
}

TEST(GasStation, Four){
    vector<int> gas ={1,2,3,3};
    vector<int> cost={2,1,5,1};
    int res = 3;
    ASSERT_EQ(res, canCompleteCircuit(gas, cost));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


