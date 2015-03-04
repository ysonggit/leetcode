#include "utils.h"
#include <gtest/gtest.h>
using namespace std;
/*
  use stack
  scan input string, keep on looking up for '/'
       if meets ./, passby;
       if meets a ../ pop (make sure stack is not empty)
       if meets other non-/ strings, push
  return string remained in the stack
  tip: use string constructor (iterator first, iterator last)
*/

string simplifyPath(string path) {    
    if(path.empty()) return "";
    vector<string> dirs;
    for(auto it=path.begin(); it!=path.end(); ){
        ++it;// pass by the first leading '/'
        auto slash = find(it, path.end(), '/');
        string dir_name = string(it, slash); // constructed from iterators
        if(dir_name == ".."){
            if(!dirs.empty()) dirs.pop_back();
        }else{
            if(dir_name!="." && !dir_name.empty()) {
                dirs.push_back(dir_name);
            }
        }
        it = slash;
    }
    if(dirs.empty()) return string("/");
    string fullpath;
    for_each(dirs.begin(), dirs.end(), [&fullpath](string & s){
            fullpath += string("/")+s;
        });

    return fullpath;
}

TEST(SimplifyPath, I){
    string path="/a/./b/../../c/";
    const char * res = "/c";
    ASSERT_STREQ(res, simplifyPath(path).c_str());
}

TEST(SimplifyPath, II){
    string path= "/home//foo";
    const char * res = "/home/foo";
    ASSERT_STREQ(res, simplifyPath(path).c_str());
}

TEST(SimplifyPath, III){
    string path="/home";
    const char * res = "/home";
    ASSERT_STREQ(res, simplifyPath(path).c_str());
}
TEST(SimplifyPath, IV){
    string path="/../";
    const char * res = "/";
    ASSERT_STREQ(res, simplifyPath(path).c_str());
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

