#include "utils.h"
#include <gtest/gtest.h>

using namespace std;
/*
  question overflow? YES: see"0.9.9.9.9.9.9.9.9.9.9"
  illegal input checking? for example: many dots 32...243?
  Can not convert string to integer for, example, "1.1"<"1.10"

  idea:
  given two versions
  00.1
  0.0.1
  find the number of dots, if not equal, append dots to make them equal
  such that
  00.1 becomes 00.1.0

  then convert two versions to long long type (in case of overflow)
  the idea is like splitting string
  so that 00.1.0 => 10
  0.0.1 => 1
  
*/ 
long long versionToLong(string version){
    int i=0;
    long long v = 0;
    version.push_back('.');
    int start_pos = 0, end_pos = 0;
    while(i<version.length()){
        if(version[i]=='.'){
            end_pos = i;
            i++;
            int cur = stoi(version.substr(start_pos, end_pos-start_pos));
            start_pos = i;// this bit should not be .
            v = v* 10 + cur;
        }else{
            i++;
            continue;
        }
    }
    return v;
}

int numberOfDots(string ver){
    int n =0;
    for_each(ver.begin(), ver.end(), [&n](char c){ 
            if(c=='.') n++; 
        });
    return n;
}
int compareVersion(string version1, string version2) {
    int num_dots_v1 = numberOfDots(version1);
    int num_dots_v2 = numberOfDots(version2);
    int diff = abs(num_dots_v1 - num_dots_v2);
    if(num_dots_v1 > num_dots_v2){
        for(int i= 0; i<diff; i++){
            version2 += string(".0");
        }
    }
    if(num_dots_v1 < num_dots_v2){
        for(int i= 0; i<diff; i++){
            version1 += string(".0");
        }
    }
    long long v1 = versionToLong(version1);
    long long v2 = versionToLong(version2);
    if(v1>v2) return 1;
    if(v1<v2) return -1;
    return 0;
}

TEST(Case, I){
    string v1 = "01";
    string v2 = "1";
    int res = 0;
    ASSERT_EQ(res, compareVersion(v1, v2));
}


TEST(Case, II){
    string v1 = "0.0.1";
    string v2 = "0.1";
    int res = -1;
    ASSERT_EQ(res, compareVersion(v1, v2));
}

TEST(Case, III){
    string v1 = "1.1";
    string v2 = "1.10";
    int res = -1;
    ASSERT_EQ(res, compareVersion(v1, v2));
}

TEST(Case, IV){
    string v1 = "1.0";
    string v2 = "0.9.9.9.9.9.9.9.9.9.9.9.9";
    int res = 1;
    ASSERT_EQ(res, compareVersion(v1, v2));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

