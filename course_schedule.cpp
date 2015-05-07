#include <gtest/gtest.h>
#include <unordered_set>
#include "utils.h"
using namespace std;

bool dfs(const vector<vector<int> > & pre_courses, vector<int> & visited, vector<int> & marked, int course){
    // has cycle
    if(visited[course]==1) return false;
    // in the topological order
    if(marked[course]==1) return true;
    visited[course] = 1;
    // for each course m with edge from course to m
    for(auto next : pre_courses[course]){
        if(!dfs(pre_courses, visited, marked, next)) return false;
    }
    // mark course permanently
    visited[course]=0;
    marked[course]=1;
    return true;
}
/*
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    if(prerequisites.size()==0) return true;
    vector< vector<int> >pre_courses(numCourses, vector<int>(0));
    for(auto coursepair : prerequisites){
        int course = coursepair[0], pre = coursepair[1];
        pre_courses[pre].push_back(course);
    }
    
    vector<int> visited(numCourses, 0);
    vector<int> marked(numCourses, 0);
    for(int i=0; i<numCourses; i++){
        if(!dfs(pre_courses, visited, marked, i)) return false;
    }
    return true;
    }*/

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    if(prerequisites.size()==0) return true;
    vector< vector<int> >pre_courses(numCourses, vector<int>(0));
    // trick use an array to save the indegree of a node
    // indegree[i] = j means for node i, indegree is j
    vector<int> indegree(numCourses, 0);
    for(auto coursepair : prerequisites){
        int course = coursepair[0], pre = coursepair[1];
        pre_courses[pre].push_back(course);
        indegree[course]++;
    }
    queue<int> courses_without_pre;
    for(int i=0; i<numCourses; i++){
        // find nodes without indegree
        if(indegree[i]==0) courses_without_pre.push(i);
    }
    while(!courses_without_pre.empty()){
        int n = courses_without_pre.front();
        courses_without_pre.pop();
        // for each m with edge e from n to m
        // remove e from graph and if for m no in edges, push to queue
        for(int m : pre_courses[n]){
            indegree[m]--;
            if(indegree[m]==0){
                courses_without_pre.push(m);
            }
        }
    }
    for(int i=0; i<numCourses; i++){
        if(indegree[i] >0) return false;
    }
    return true;
}


TEST(COURSE, I){
    vector<vector<int>> prerequisites{
        {1, 0}
    };
    int numCourses = 3;
    bool res = true;
    ASSERT_EQ(res, canFinish(numCourses, prerequisites));
}

TEST(COURSE, II){
    vector<vector<int>> prerequisites{
        {1, 0},
        {0, 1}
    };
    int numCourses = 2;
    bool res = false;
    ASSERT_EQ(res, canFinish(numCourses, prerequisites));
}

TEST(COURSE, III){
    vector<vector<int>> prerequisites{
        {5, 6},
        {0, 2},
        {1, 7},
        {5, 9},
        {1, 8},
        {3, 4},
        {0, 6},
        {0, 7},
        {0, 3},
        {8, 9}
    };
    int numCourses = 10;
    bool res = true;
    ASSERT_EQ(res, canFinish(numCourses, prerequisites));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}