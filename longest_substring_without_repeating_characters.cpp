#include "utils.h"
#include <gtest/gtest.h>

using namespace std;

// assume given string contains only a-z 
// use an array of 26 to track the number the character shows up
// for example, count[0] = 2 means 'a'' shows twice
int lengthOfLongestSubstring(string s) {
    if(s.length()==0) return 0;
    int walker=0, runner=0;
    int max_len = 0;
    unordered_map<char, int> count;
    int n = s.length();
    while( runner < n ){
        char key = s[runner];
        if(count[key]<1){
            count[key]++;
        }
        else{
            while(s[walker]!= s[runner]){
                char key_to_reset = s[walker];
                count[key_to_reset] = 0;
                walker++;
            }
            walker++; // compute the length starting from the next character of the existed ones 
        }
        runner++;
        max_len = max(max_len, runner-walker);
    }
    return max_len;
}

TEST(MyTest, One){
    string s("abcdcdef");
    int res = 4;
    ASSERT_EQ(res, lengthOfLongestSubstring(s));
}

TEST(MyTest, Two){
    string s("bbbbbb");
    int res = 1;
    ASSERT_EQ(res, lengthOfLongestSubstring(s));
}

TEST(MyTest, Three){
    string s("abcabcbb");
    int res = 3;
    ASSERT_EQ(res, lengthOfLongestSubstring(s));
}

TEST(MyTest, Four){
    string s("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco");
    int res = 12;
    ASSERT_EQ(res, lengthOfLongestSubstring(s));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

