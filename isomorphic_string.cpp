#include <gtest/gtest.h>
#include "utils.h"
using namespace std;
/*
  Given two (dictionary) words as Strings, determine if they are isomorphic.

Two words are called isomorphic if the letters in one word can be remapped to get the second word. 

Remapping a letter means replacing all occurrences of it with another letter while the ordering of the letters remains unchanged. No two letters may map to the same letter, but a letter may map to itself. 

Example: 
given "foo", "app"; returns true 

we can map 'f' -> 'a' and 'o' -> 'p' 
given "bar", "foo"; returns false 
we can't map both 'a' and 'r' to 'o'

given "turtle", "tletur"; returns true 
we can map 't' -> 't', 'u' -> 'l', 'r' -> 'e', 'l' -> 'u', 'e' -'r'

given "ab", "ca"; returns true 
we can map 'a' -> 'c', 'b'

Idea: 
1) for the i-th character in string s, build forward mapping to the i-th character in string t;
2) for the i-th character in string t, build backward mapping to the i-th character in string s;
3) each pair of characters either forms new forward mapping and backward mapping, or does not contradict to the existed mappings
otherwise, they are not isomorphic
 */
bool isomorphic(string s, string t){
    if(s.length()!=t.length()) return false;
    if(s==t) return true;
    unordered_map<char, char> forwardmapping;
    unordered_map<char, char> backmapping;
    for(int i=0; i<s.length(); i++){
        char sc = s[i], tc = t[i];
        if(forwardmapping.find(sc)!= forwardmapping.end()){
            if(forwardmapping[sc] != tc) return false;
        }else{
            forwardmapping[sc] = tc;
        }
        if(backmapping.find(tc)!= backmapping.end()){
            if(backmapping[tc]!=sc) return false;
        }else{
            backmapping[tc] = sc;
        }
    }
    return true;
}

TEST(Isomorphic, I){
    string s("foo");
    string t("app");
    bool res = true;
    ASSERT_EQ(res, isomorphic(s, t));
}

TEST(Isomorphic, II){
    string s("foo");
    string t("ppa");
    bool res = false;
    ASSERT_EQ(res, isomorphic(s, t));
}

TEST(Isomorphic, III){
    string s("turtle");
    string t("tletur");
    bool res = true;
    ASSERT_EQ(res, isomorphic(s, t));
}

TEST(Isomorphic, IV){
    string s("ab");
    string t("ca");
    bool res = true;
    ASSERT_EQ(res, isomorphic(s, t));
}

TEST(Isomorphic, V){
    string s("bar");
    string t("foo");
    bool res = false;
    ASSERT_EQ(res, isomorphic(s, t));
}

TEST(Isomorphic, VI){
    string s("bar");
    string t("bar");
    bool res = true;
    ASSERT_EQ(res, isomorphic(s, t));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

