#include "utils.h"

using namespace std;

/*
  example:
  Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
  idea: O(n^2) time O(1) space
  starting from the first interval, find the position to insert given interval
  if no interval or all intervals end before newInterval.start, insert to the end of the list
  for the interval i,
  1 if newInterval.end < i.start
      insert newInterval here
  2 if newInterval.start  <= i.end 
     1) extend newInterval by  merging it with i
     2) erase original interval i
  Time Limit Exceeded

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval>::iterator iter = intervals.begin();
    while(iter != intervals.end()){
        if(newInterval.end < iter->start){
            intervals.insert(iter, newInterval);
            return intervals;
        }else if(newInterval.start > iter->end){
            iter++;
            continue;
        }else{
            newInterval.start = min(newInterval.start, iter->start);
            newInterval.end = max(newInterval.end, iter->end);
            intervals.erase(iter); // erase takes linear time 
        }
    }
    // for case the new interval should be the last one in the list
    intervals.insert(intervals.end(), newInterval);
    
    return intervals;
    }
*/
/*
  Optimiazed version: O(n) time , O(n) space
  20 ms
 */

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> res;
    auto iter = intervals.begin();
    bool inserted = false;
    for( ; iter != intervals.end(); ++iter){
        if(newInterval.end< iter->start){
            if(!inserted){
                inserted = true;
                res.push_back(newInterval);
            }
            res.push_back(*iter);
        }
        else if(newInterval.start > iter->end){
            res.push_back(*iter);
        }else{
            newInterval.start = min(newInterval.start, iter->start);
            newInterval.end = max(newInterval.end, iter->end);
        }
    }
    if(!inserted) res.push_back(newInterval);
    return res;
}

int main(int argc, char *argv[]){
    vector<Interval> its;
    int starts [] = {1,3,6,8,12};
    int ends [] = {2,5,7,10,16};
    for(int i=0; i<5; i++){
        its.push_back(Interval(starts[i], ends[i]));
    }
    Interval ni(4,9);
    vector<Interval> results = insert(its, ni);
    printVector(results);
    return 0;
}
