#include "utils.h"
//#include <cfloat> // DBL_MAX
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

bool samePoint(const Point& a, const Point& b){
    return (a.x==b.x) && (a.y==b.y);
}
/*
  idea: brute-force O(n^3)
        for n points, find all n*(n-1)/2 lines
        for each line search rest n-2 points and count the number of colinear
        keep track of the max points

   question: does the given array of points contain multiple points equal to the same one?
   result: time exceeds

   bool colinear(Point a, Point b, Point c){
   return ((a.x-b.x) * (a.y-c.y)) == ((a.x-c.x)*(a.y-b.y));
   }
   int maxPoints(vector<Point> &points) {
    int n = points.size();
    if(n==0) return 0;
    int global_max = 0;
    // corner case: if all points are the same return the size of vector
    int count = 1;
    for(int i=0; i<n; i++){
        if(samePoint(points[i], points[0])) count++;
    }
    if(count == n) return n;

    for(int i=0; i<n; i++){
        Point a = points[i];
        for(int j=0; j<n; j++){
            if (j!=i){
                Point b = points[j];
                int local_max = 0;
                for(int k=0; k<n; k++){
                    if(k != j && k!= i){
                        Point c = points[k];
                        // check if c is on the line ab
                        if(colinear(a, b, c)){
                            local_max++;
                        }
                    }
                }
                global_max = max(local_max, global_max);
            }
        }
    }
    return global_max;
}
*/
/*O(n^2) time O(n) space
  For point i, scan rest n-i-1 points
  maintain the hashmap, key is the slope of line ij (i < j < n)
                        value is the number of lines

  return the max value of the hashmap
 */

int slope(const Point & a, const Point & b){
    if(a.x==b.x) return  INT_MAX;
    return (int) 1e5 * (double)(a.y-b.y)/(double)(a.x-b.x);
}

int maxPoints(vector<Point> &points){
    int n = points.size();
    if(n==0) return 0;
    // corner case: if all points are the same return the size of vector
    int global_max = 0;
    for(int i=0; i<n; i++){
        Point a =  points[i];
        unordered_map<int, int> lines; // questionable
        int local_max = 1;
        //cout<<"for Point "<<i<<endl;
        int points_duplicated = 0;
        for(int j=i+1; j<n; j++){
            Point b = points[j];
            //cout<<"point "<<j;
            if(samePoint(a, b)){
                points_duplicated++; // same points are considered on the same line
            }else{
                int ab = slope(a, b);
                if(lines.find(ab) != lines.end()){
                    //cout<<" on the existed line of slope "<<ab<<endl;
                    lines[ab] += 1;
                }else{
                    //cout<<" create a new line with slope "<<ab<<endl;
                    lines[ab] = 2;
                }
            }
        }
        for(auto iter = lines.begin(); iter != lines.end(); ++iter){
            local_max = max(iter->second, local_max);
        }
        global_max = max(local_max+points_duplicated, global_max);
    }
    return global_max;
}

int main(int argc, char *argv[])
{
    int xy[] = {0,0, 0,0, 0,0, 1,1} ;
    vector<Point> points;
    for(int i=0; i<4; i++){
        points.push_back(Point(xy[i*2], xy[i*2+1]));
    }
    cout<<maxPoints(points)<<endl;
    return 0;
}


