#include "utils.h"
#include <gtest/gtest.h>
#include <unordered_set>

using namespace std;

/*
  start = "hit"
  end = "cog"
  dict=["hot","dot","dog","lot","log"]

  idea :
  1. BFS build tree rooted at the start string
  2. DFS find all paths ending at the end string

              hit
               |
              hot
               |
       dot --- |----- lot
        |              |
       dog ----------log
               |
              cog

*/
typedef unordered_map<string, unordered_set<string> > WordTree;

void printWordTree(const WordTree & word_tree){
    for(auto it = word_tree.begin(); it!=word_tree.end(); ++it){
        cout<<"("<<it->first<<") --> \n";
        for(auto cit = it->second.begin(); cit!= it->second.end(); ++cit){
            cout<<"\t("<<(*cit)<<")\n";
        }
    }
}

bool nextWord(string wd1, string wd2){
    int count = 0;
    for(int i=0; i<wd1.length(); i++){
        if(wd2[i] == wd1[i]) count++;
    }
    return (count == wd1.length()-1) ? true : false;
}

int buildWordTree(string start, string end, unordered_set<string> & dict, WordTree & word_tree){
    if(start.empty() || end.empty() || dict.size()==0 ) return 0;
    unordered_set<string> visited;
    visited.insert(start);
    set<string> current, next;
    current.insert(start);
    bool minimal_steps_found = false;
    int level = 1;
    while(!current.empty()){
        string wd = *current.begin();
        current.erase(current.begin());
        if(word_tree.count(wd)<1){
            unordered_set<string> children;
            word_tree.insert(make_pair(wd, children) );
        }
        for(int i=0; i<wd.length(); i++){
            char cur = wd[i];
            string wd_cp(wd);
            for(char c='a'; c<='z'; c++){
                if(cur != c){
                    wd[i] = c;
                    if(dict.find(wd)!=dict.end()){
                        if(visited.find(wd) == visited.end()){
                            visited.insert(wd);
                            next.insert(wd);
                        }
                    }
                    if(wd==end){
                        word_tree[wd].insert(end);
                        if(!minimal_steps_found){
                            level++;
                            minimal_steps_found = true;
                        }
                    }
                    wd[i] = cur;
                }
            }
        }
        for(auto it=next.begin(); it!= next.end(); ++it){
            if(nextWord(*it, wd)){
                word_tree[wd].insert(*it);
            }
        }
        if(current.size()==0){
            current.swap(next);
            if(!minimal_steps_found) level++;
        }
    }
    return level;
}

void dfs(vector<vector<string> > & paths, vector<string> & ladder, unordered_set<string> & visited, string cur, WordTree & word_tree, string& end, int steps){
    if(ladder.size()==steps){
        if(ladder.back()==end){
            paths.push_back(ladder);
            return ;
        }
    }
    for(auto it = word_tree[cur].begin(); it!= word_tree[cur].end(); ++it){
        string nex_wd = *it;
        if(visited.count(nex_wd) < 1){
            ladder.push_back(nex_wd);
            visited.insert(nex_wd);
            dfs(paths, ladder, visited, nex_wd, word_tree, end, steps);
            ladder.pop_back();
            visited.erase(visited.find(nex_wd));
        }
    }
}

vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
    vector<vector<string> >paths;
    if(start.empty() || end.empty() || dict.size()==0 ) return paths;
    WordTree word_tree;
    int steps = buildWordTree(start, end, dict, word_tree);
    // cout<<"steps = "<<steps<<endl;
    // printWordTree(word_tree);
    unordered_set<string> visited;
    vector<string> ladder;
    ladder.push_back(start);
    dfs(paths, ladder, visited, start, word_tree, end, steps);
    return paths;
}

TEST(LADDER, I){
    string start("hit");
    string end("cog");
    unordered_set<string> dict={"hot", "dot", "dog", "lot", "log"};
    vector<vector<string> >results = findLadders(start, end, dict);
    print2DVector(results);
}

TEST(LADDER, II){
    string start("a");
    string end("c");
    unordered_set<string> dict={"a", "b", "c"};
    vector<vector<string> >results = findLadders(start, end, dict);
    print2DVector(results);
}

TEST(LADDER, III){
    string start("red");
    string end("tax");
    unordered_set<string> dict={"ted","tex","red","tax","tad","den","rex","pee"};
    vector<vector<string> >results = findLadders(start, end, dict);
    print2DVector(results);
}

TEST(LADDER, IV){
    string start("qa");
    string end("sq");
    unordered_set<string> dict= {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
    vector<vector<string> >results = findLadders(start, end, dict);
    print2DVector(results);
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
