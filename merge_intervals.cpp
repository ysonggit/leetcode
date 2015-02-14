#include "utils.h"
#include <gtest/gtest.h>

using namespace std;

/*
  idea O(n) time O(n) space
  sort intervals
  merge two adjacent intervals with overlap
*/

struct {
    bool operator() (const Interval & a, const Interval & b){
        return a.start < b.start;
    }
} less_than;

vector<Interval> merge(vector<Interval> &intervals) {
    if(intervals.size()<=1) return intervals;
    sort(intervals.begin(), intervals.end(), less_than);
    vector<Interval> res;
    Interval cur = intervals[0];
    for(int i=1; i<intervals.size(); i++){
        // if no overlap , push cur into res
        if(cur.end < intervals[i].start){
            res.push_back(cur);
            cur = intervals[i];
        }else{
            // otherwise, merge until no overlap
            //cur.start = min(cur.start, intervals[i].start);
            cur.end = max(cur.end, intervals[i].end);
        }
    }
    res.push_back(cur);
    return res;
}

/*
  inputs an array {{1,3},{2,6}}, outputs a vector of intervals
 */
void intervalsInitializer(vector<Interval> & intervals, vector<vector<int> > vals){
    for(vector<int> v: vals){
        if(v.size() != 2) return;
        intervals.push_back(Interval(v[0], v[1]));
    }
}

/*
  For example,
  Given [1,3],[2,6],[8,10],[15,18],
  return [1,6],[8,10],[15,18].
 */
TEST(MergeIntervals, I){
    vector<vector<int> > vals = {
        {1,3},{2,6},{8,10}, {15,18}
    };
    vector<Interval> intervals;
    intervalsInitializer(intervals, vals);
    printVector(merge(intervals));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


