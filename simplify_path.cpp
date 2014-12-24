#include "utils.h"
#include <gtest/gtest.h>
using namespace std;
/*
  use stack
  scan input string
       if meets ./, passby;
       if meets a ../ pop
       if meets other non-/ strings, push
  return string remained in the stack

  /a/./b/../../c/
  push a
  pass ./
  push b
  pop b
  pop a
  push c
  return /+c

*/
vector<string> splitPath(const string &path, char delim){
    istringstream iss(path);
    string item;
    vector<string> tokens;
    while(getline(iss, item, delim)){
        tokens.push_back(item);
    }
    return tokens;
}

string simplifyPath(string path) {
    stack<string> s;
    string result;
    vector<string> tokens = splitPath(path, '/');
    for(int i=0; i<tokens.size(); i++){
        string cur = tokens[i];
        if(cur != "." && cur != ".." && !cur.empty()) {
            s.push(cur);
            continue;
        }
        if(cur == "." || cur.empty()) continue;//  /home//foo
        if(cur == ".." && !s.empty()){
            s.pop();
        }
    }
    stack<string> dirs;
    while(!s.empty()){
        dirs.push(s.top());
        s.pop();
    }
    if(dirs.empty()){
        return string("/");
    }
    while(!dirs.empty()){
        result += string("/") + dirs.top();
        dirs.pop();
    }
    return result;
}

int main(int argc, char *argv[]){
    //testing::InitGoogleTest(&argc, argv);
    //return RUN_ALL_TESTS();
    string paths[] = {"/a/./b/../../c/", "/home//foo", "/home/", "/../"};
    string results[] = {"/c", "/home/foo", "/home", "/"};
    for(int i=0; i<4; i++){
        cout<<simplifyPath(paths[i])<<endl;
    }
    return 0;
}

