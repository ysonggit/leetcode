#include "utils.h"
#include <gtest/gtest.h>

using namespace std;
/*
  idea : two pointers, skip any non alphabetic or decimal digit characters
  O(n) time O(1) space
*/
bool isPalindrome(string s) {
    if(s.empty()) return true;
    int front = 0; int back= s.length()-1;
    transform (s.begin(), s.end(), s.begin(), ::tolower);
    while(front<back){
        while(front<back && !isalnum(s[front])) front++;
        while(front<back && !isalnum(s[back])) back--;
        if(s[front]==s[back]){
            front++;
            back--;
        }else{
            return false;
        }
    }
    return true;
}

TEST(Palindrome, I){
    string s("A man, a plan, a canal: Panama");
    bool res = true;
    ASSERT_EQ(res, isPalindrome(s));
}

TEST(Palindrome, II){
    string s("race a car");
    bool res = false;
    ASSERT_EQ(res, isPalindrome(s));
}

TEST(Palindrome, III){
    string s("");
    bool res = true;
    ASSERT_EQ(res, isPalindrome(s));
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


