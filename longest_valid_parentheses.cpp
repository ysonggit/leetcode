#include "utils.h"
#include <gtest/gtest.h>
using namespace std;

/*
  idea : stack (refer to valid parentheses)
  use stack to store the indices of un-matched left parentheses
  http://blog.csdn.net/worldwindjp/article/details/39460161
  max_len = 0, start = 0
  for i = 0 ... n-1
      if s[i] == '('
         push i
      else
         if stack.empty()
            update start as the index of current ')' + 1
         else
            stack.pop
            if stack.empty()
               max_len = max(max_len, i + start - 1)
            else
               max_len = max(max_len, i + 1 - stack.top)

 */

int longestValidParentheses(string s) {
    if (s.length()==0 ) return 0;
    int max_len  = 0, start = 0;
    stack<int> unmatch;
    for(int i=0; i < s.length(); i++){
        if(s[i]=='('){
            unmatch.push(i);
        }else{
            if (!unmatch.empty()){
                unmatch.pop();
                if(unmatch.empty()){
                    max_len = max(max_len, i - start + 1);
                }else{
                    max_len = max(max_len, i - unmatch.top() );
                }
            }else{
                start = i+1;
            }
        }
    }
    return max_len;
}

TEST(Case, One){
    string s = ")()())";
    int res = 4;
    ASSERT_EQ(res, longestValidParentheses(s));
}

TEST(Case, Two){
    string s = "())()()";
    int res = 4;
    ASSERT_EQ(res, longestValidParentheses(s));
}

TEST(Case, Three){
    string s = "()(()()";
    int res = 4;
    ASSERT_EQ(res, longestValidParentheses(s));
}

TEST(Case, Four){
    string s = "()(()())";
    int res = 8;
    ASSERT_EQ(res, longestValidParentheses(s));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

