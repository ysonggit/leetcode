#include <gtest/gtest.h>
#include "utils.h"
using namespace std;
/*
  question:
  given a compressed string "a#3bd#4"
  decompress it as aaabdddd
  assume every input string is legal 
*/
string decompress(string str){
    if(str.empty()) return str;
    int n = str.length();
    string res;
    int i = 0;
    while(i<n){
        if(isalpha(str[i]) ){
            res.push_back(str[i]);
            if(i+1<n && str[i+1] =='#'){
                int num = (int) str[i+2] -'0';
                for(int k=0; k<num-1; k++){
                    res.push_back(str[i]);
                }
                i += 3;
            }else{
                i += 1;
            }
        }
    }
    return res;
}

TEST(B, I){
    string str("a#3bd#4");
    string res("aaabdddd");
    ASSERT_STREQ(res.c_str(), decompress(str).c_str());
}

TEST(B, II){
    string str("abcdefg");
    string res("abcdefg");
    ASSERT_STREQ(res.c_str(), decompress(str).c_str());
}

TEST(B, III){
    string str("a#2");
    string res("aa");
    ASSERT_STREQ(res.c_str(), decompress(str).c_str());
}

TEST(B, IV){
    string str("bd#5cx#4y");
    string res("bdddddcxxxxy");
    ASSERT_STREQ(res.c_str(), decompress(str).c_str());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
