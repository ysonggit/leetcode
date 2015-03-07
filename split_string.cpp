#include <gtest/gtest.h>
#include "utils.h"
using namespace std;
/*
  
Given a string split by space.
But the spaces between a pair of single quotations does not count as a separator.
(assume there are even number of single quotations) 
examples: 
s = "abc de  "
output: ["abc", "de"]

s = "abcd' 'de"
output: [“abc' 'de”]

s=”abcd' ' ' 'de”
output: ["abcd' '", "' 'de"]

s="abcd' 'de' ' ' 'f"
output: ["abcd' 'de' '", "' 'f"]

s="a   b  "
output: ["a", "b"]

s="a'   'b    "
output : ["a'   'b"]

s="    "
output: []
 */
vector<string> splitString(string s){
    if(s.empty()) return vector<string>{};
    vector<string> res;
    s.push_back(' ');
    int n = s.length();
    int i = 0;
    int start_pos = 0, end_pos = 0;
    bool single_quote_found = false;
    while(i<n){
        if(s[i] == ' '){
            end_pos = i;
            int len = end_pos - start_pos;
            i++;
            while(s[i]==' ') i++;
            if(!single_quote_found){
                if(len>0) res.push_back(s.substr(start_pos, len));
                start_pos = i;
            }
        }
        if(s[i]!='\'' && s[i] != ' '){ i++; continue; }
        if(s[i]=='\''){
            i++;
            single_quote_found = (single_quote_found) ? false : true;
        }
    }
    return res;
}

TEST(Split, I){
    string s("abc    de");
    printVector(splitString(s));
}

TEST(Split, II){
    string s("abc' 'de");
    printVector(splitString(s));
}

TEST(Split, III){
    string s("a'   'b   ");
    printVector(splitString(s));
}

TEST(Split, IV){
    string s("ab' ' ' 'de");
    printVector(splitString(s));
}

TEST(Split, V){
    string s("    ");
    printVector(splitString(s));
}

TEST(Split, VI){
    string s="abcd' 'de' ' ' 'f";
    printVector(splitString(s));
}

TEST(Split, VII){
    string s("a    b   ");
    printVector(splitString(s));
}

TEST(Split, VIII){
    string s("    a    b");
    printVector(splitString(s));
}

TEST(Split, IX){
    string s("a");
    printVector(splitString(s));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


