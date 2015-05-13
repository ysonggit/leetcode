#include <gtest/gtest.h>
#include "utils.h"
using namespace std;
vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    if(numCourses==0) return vector<int>(); // mistake : if prerequisites is empty, should return lists directly
    vector<vector<int> >  pre_posts (numCourses, vector<int>(0));
    vector<int> indegree(numCourses, 0); // indegrees[i] =j means course i has j prerequisites
    for(auto coursepair : prerequisites){
        int post = coursepair.first;
        int pre = coursepair.second;
        indegree[post]++;
        pre_posts[pre].push_back(post);
    }
    queue<int> courses_without_pre;
    for(int i=0; i<numCourses; i++){
        if(indegree[i]==0) courses_without_pre.push(i);   
    }
    vector<int> topo_order;
    while(!courses_without_pre.empty()){
        int pre = courses_without_pre.front();
        courses_without_pre.pop();
        topo_order.push_back(pre);
        // for each m with an edge e from n -> m
        // remove e
        for(auto post : pre_posts[pre]){
            indegree[post]--;
            if(indegree[post]==0) {
                courses_without_pre.push(post);
            }
        }
    }
    for(int i=0; i<indegree.size(); i++){
        if(indegree[i]>0) return vector<int>();
    }
    return topo_order;
}

TEST(CourseSchedule, I){
    int numCourses = 2;
    vector<pair<int, int> >  prerequisites{
        pair<int, int>{1,0}, pair<int, int>{0,1}
    };
    vector<int> order = findOrder(numCourses, prerequisites);
    printVector(order);
}

TEST(CourseSchedule, II){
    int numCourses = 4;
    vector<pair<int, int> >  prerequisites{
        pair<int, int>{1,0}, pair<int, int>{2,0}, pair<int, int>{3,1}, pair<int, int>{3,2}
    };
    vector<int> order = findOrder(numCourses, prerequisites);
    printVector(order);
}

TEST(CourseSchedule, III){
    int numCourses = 1;
    vector<pair<int, int> >  prerequisites{};
    vector<int> order = findOrder(numCourses, prerequisites);
    printVector(order);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

