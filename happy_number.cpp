#include <gtest/gtest.h>
#include "utils.h"
#include <unordered_set>

using namespace std;
unordered_set<int> existed;
bool isHappy(int n){
    if(existed.find(n) == existed.end()){
        existed.insert(n);
    }else{
        return false;
    }
    stringstream ss;
    ss<<n;
    int m =0;
    for(char c : ss.str()){
        m += pow(c-'0',2);
    }
    if(m==1) return true;
    return isHappy(m);
}

TEST(Happy, I){
    int n = 19;
    bool res = true;
    ASSERT_EQ(res, isHappy(n));
    existed.clear();
}

TEST(Happy, II){
    int n = 22;
    bool res = false;
    ASSERT_EQ(res, isHappy(n));
    existed.clear();
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


