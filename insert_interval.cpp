#include "utils.h"

using namespace std;
// assume it1 has overlap with it2
Interval mergeIntervals(Interval & it1, Interval & it2){
    int _start = min(it1.start, it2.start);
    int _end = max(it1.end, it2.end);
    return Interval(_start, _end);
}

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> result;
    // 1. find the position to insert the new interval
    int i=0;
    while( i< intervals.size()){
        Interval it = intervals[i];
        if( it.start <= newInterval.start && it.end>=  newInterval.end){
            return intervals;
        }
        if(it.end< newInterval.start){
            result.push_back(it);
        }else{
            break;
        }
        i++;
    }
    // 2. insert the new interval
    result.push_back(newInterval);
    // 3. check overlap of the new interval and following intervals
    while(i<intervals.size()){
        Interval cur_it = intervals.at(i);
        if(result.back().end >= cur_it.start ){
            result.back() = mergeIntervals(result.back(), cur_it);
            i++;
        }else{
            break;
        }
    }
    // 4. append the rest intervals (if any)
    while(i<intervals.size()){
        result.push_back(intervals.at(i));
        i++;
    }
    return result;
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
