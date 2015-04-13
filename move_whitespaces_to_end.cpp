#include "utils.h"
#include <gtest/gtest.h>
using namespace std;
/*
  given a string containing white spaces, move all spaces to the end of the string inplace

  idea: similar to move zeros to right

  source: bloomberg
  
 */

void moveSpacesToEnd(string & s){
    if(s.empty()) return;
    int n = s.length();
    int j = 0;
    for(int i=0; i<n; i++){
        if(s[i]!=' '){
            s[j]=s[i];
            j++;
        }
    }
    while(j<n){
        s[j] = ' ';
        j++;
    }
}

TEST(MoveSpaces, I){
    string s("  Here I     am   ");
    cout<<s<<endl;
    moveSpacesToEnd(s);
    cout<<s<<endl;
}

TEST(MoveSpaces, II){
    string s("     ");
    cout<<s<<endl;
    moveSpacesToEnd(s);
    cout<<s<<endl;
}

TEST(MoveSpaces, III){
    string s("Here");
    cout<<s<<endl;
    moveSpacesToEnd(s);
    cout<<s<<endl;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}