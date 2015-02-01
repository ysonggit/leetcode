#include "utils.h"
#include <gtest/gtest.h>

using namespace std;

/*
  1. whitespace skip (only whitespaces?)
  2. +/- sign check
  3. overflow (return -INT_MIN or INT_MAX)
  4. empty string
  question : how about this one str="  -  012   3.12"? 
          
  function: isdigit(int c)

  WTF! they do have such test case: "  -0012a42" should return -12
        " +0 123" return 0  instead of 123
        " + 321" return 0  instead of 321 
 */
int atoi(const char *str){
    if(str==NULL || str=='\0') return 0;
    int num = 0;
    int i=0;
    int n= strlen(str);
    while(i<n && str[i]==' ') i++;
    if(i==n) return num; // only whitespaces
    // now i points to the first non-whitespace character
    // could be sign +/- or +-
    int sign = 1;
    if(str[i] == '-'){
        sign = -1;
        i++;
        if(!isdigit(str[i]) && str[i]!=' ') return 0;
    }
    if(str[i]=='+'){
        i++;
        if(!isdigit(str[i]) && str[i]!=' ') return 0;
    }     
    // now i points to a whitespace or a digit
    //while(str[i]==' '&& i<n) i++;
    // if it is a whitespace, then return 0
    for(; i<n; i++){
        if(!isdigit(str[i]) || str[i] == ' ') break;
        if(isdigit(str[i])){
            // MUST check range ahead, otherwise num is computed incorrect
            // http://fisherlei.blogspot.com/2013/01/leetcode-string-to-integer-atoi.html
            if(num > INT_MAX/10 || (num == INT_MAX/10 && INT_MAX%10 < (str[i]-'0') ) ){
                return (sign > 0) ? INT_MAX : INT_MIN;
            }
            num = num * 10 +  (int) str[i] - '0';
        }
    }
    return sign*num;
}

TEST(ATOI, I){
    const char * str = "  -1235 34";
    int res = -1235;
    ASSERT_EQ(res, atoi(str));
}

TEST(ATOI, II){
    const char * str = "      ";
    int res = 0;
    ASSERT_EQ(res, atoi(str));
}

TEST(ATOI, III){
    const char * str = "  +21474836489 ";
    int res = INT_MAX;
    ASSERT_EQ(res, atoi(str));
}

TEST(ATOI, IV){
    const char * str = "+214";
    int res = 214;
    ASSERT_EQ(res, atoi(str));
}

TEST(ATOI, V){
    const char * str = "+-214";
    int res = 0;
    ASSERT_EQ(res, atoi(str));
}

TEST(ATOI, VI){
    const char * str = "  -0012a43";
    int res = -12;
    ASSERT_EQ(res, atoi(str));
}

TEST(ATOI, VII){
    const char * str = "  +0  123";
    int res = 0;
    ASSERT_EQ(res, atoi(str));
}



int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

