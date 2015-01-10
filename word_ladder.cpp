#include "utils.h"
#include <gtest/gtest.h>
#include <unordered_set>

using namespace std;

int ladderLength(string start, string end, unordered_set<string> &dict) {
    if(dict.size()==0 || start.length() != end.length() || start.length()==0 || end.length()==0) return 0;
    queue<string> Q;
    unordered_set<string> visited;
    int level = 1;
    Q.push(start);
    visited.insert(start);
    int num_cur_level = 1;
    int num_nex_level = 0;
    while(!Q.empty()){
        string wd = Q.front();
        Q.pop();
        num_cur_level--;
        // determine all edges connecting wd to other words
        // maximal 25*L edges
        for(int i=0; i<wd.length(); i++){
            char cur = wd[i];
            for(char c='a'; c<='z'; c++){
                if(c!=cur){
                    wd[i] = c; // now the wd is not "wd" in line 14
                    if(wd == end) return level+1;
                    if(dict.find(wd)!=dict.end()){
                        // an edge found
                        // string wd_one_char_diff = wd;
                        if(visited.find(wd) == visited.end()){
                            num_nex_level++;
                            visited.insert(wd);
                            Q.push(wd);
                        }
                    }
                    wd[i] = cur; // recover original wd
                }
            }
        }
        if(num_cur_level==0){
            // move to next level
            swap(num_cur_level, num_nex_level);
            level++;
        }
    }
    return 0;
}

TEST(Ladder, One){
    string start("hit");
    string end("cog");
    unordered_set<string> dict={"hot", "dot", "dog", "lot", "log"};
    int res = 5;
    ASSERT_EQ(res, ladderLength(start, end, dict));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

