#include "utils.h"
#include <gtest/gtest.h>

using namespace std;
/*
  idea: use stack
  if meet a left paren, push stack
  if meet a right paren, compare with top, if match pop, otherwise invalid
 */

bool isValid(string s){
    if(s.empty()) return true;
    stack<char> left_parens;
    for(char c : s){
        if(left_parens.empty() || c=='(' || c=='[' || c=='{'){
            left_parens.push(c);
        }else{
            if(!left_parens.empty()){
                char left = left_parens.top();
                if(c==')' && left !='(') return false;
                if(c==']' && left !='[') return false; 
                if(c=='}' && left !='{') return false;
                left_parens.pop();
            }
        }
    }
    return left_parens.empty() ? true : false;
}

TEST(ValidParentheses, I){
    string s("()[]{}");
    bool res = true;
    ASSERT_EQ(res, isValid(s));
}

TEST(ValidParentheses, II){
    string s("([)]");
    bool res = false;
    ASSERT_EQ(res, isValid(s));
}
TEST(ValidParentheses, III){
    string s("(])");
    bool res = false;
    ASSERT_EQ(res, isValid(s));
}
int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


