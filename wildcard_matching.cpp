#include "utils.h"
#include <gtest/gtest.h>

using namespace std;

bool isMatch(const char * s, const char * p){

}

TEST(WildcardMatching, I){
    const char * s = "aa";
    const char * p = "*";
    bool res = true;
    ASSERT_EQ(res, isMatch(s, p));
}

TEST(WildcardMatching, II){
    const char * s = "aa";
    const char * p = "a*";
    bool res = true;
    ASSERT_EQ(res, isMatch(s, p));
}


TEST(WildcardMatching, II){
    const char * s = "ab";
    const char * p = "?*";
    bool res = true;
    ASSERT_EQ(res, isMatch(s, p));
}

TEST(WildcardMatching, IV){
    const char * s = "aab";
    const char * p = "c*a*b";
    bool res = false;
    ASSERT_EQ(res, isMatch(s, p));
}


int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


