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

   Time Limit Exceeded (WTF)
*/

struct WordTreeNode{
    string word;
    unordered_set<WordTreeNode*> children;
    WordTreeNode(string s) : word(s), children(){}
};

void printWordTree(const unordered_map<string, WordTreeNode*> & word_tree){
    for(auto it = word_tree.begin(); it!=word_tree.end(); ++it){
        cout<<"("<<it->first<<") --> \n";
        WordTreeNode * n = it->second;
        for(auto cit = n->children.begin(); cit!= n->children.end(); ++cit){
            cout<<"\t("<<(*cit)->word<<")\n";
        }
    }
}

int buildWordTree(string start, string end, unordered_set<string> & dict, unordered_map<string, WordTreeNode*> & word_tree){
    if(start.empty() || end.empty() || dict.size()==0 ) return 0;
    queue<string> Q;
    unordered_set<string> visited;
    Q.push(start);
    visited.insert(start);
    WordTreeNode * root = new WordTreeNode(start);
    word_tree.insert(make_pair(start, root));
    WordTreeNode * leaf = new WordTreeNode(end);
    word_tree.insert(make_pair(end, leaf));
    int num_cur_level = 1;
    int num_nex_level = 0;
    int level = 1;
    bool minimal_steps_found = false;
    while(!Q.empty()){
        string wd = Q.front();
        Q.pop();
        num_cur_level--;
        for(int i=0; i<wd.length(); i++){
            char cur = wd[i];
            string wd_cp(wd);
            for(char c='a'; c<='z'; c++){
                if(cur != c){
                    wd[i] = c;
                    if(dict.find(wd)!=dict.end()){
                        if(word_tree.count(wd)<1){
                            word_tree.insert(make_pair(wd, new WordTreeNode(wd)));   
                        }
                        if(word_tree[wd_cp]->children.count(word_tree[wd]) < 1){
                            (word_tree[wd_cp]->children).insert(word_tree[wd]);
                        }
                        if(visited.find(wd) == visited.end()){
                            num_nex_level++;
                            visited.insert(wd);
                            Q.push(wd);
                        }
                    }
                    if(wd==end){
                        (word_tree[wd_cp]->children).insert(word_tree[end]);
                        if(!minimal_steps_found){
                            level++;
                            minimal_steps_found = true;
                        }
                    }
                    wd[i] = cur;
                }
            }
        }
        if(num_cur_level==0){
            swap(num_cur_level, num_nex_level);
            if(!minimal_steps_found) level++;
        }
    }
    return level;
}

void dfs(vector<vector<string> > & paths, vector<string> & ladder, unordered_set<string> & visited, string cur, unordered_map<string, WordTreeNode*> & word_tree, string& end, int steps){
    WordTreeNode * cur_node = word_tree[cur];
    if(ladder.size()==steps){
        if(ladder.back()==end ){
            paths.push_back(ladder);
            return ;
        }
    }
    for(auto it=cur_node->children.begin(); it != cur_node->children.end(); ++it){
        string nex_wd = (*it)->word;
        if(visited.find(nex_wd) == visited.end()){
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
    unordered_map<string, WordTreeNode*> word_tree;
    int steps = buildWordTree(start, end, dict, word_tree);
    //cout<<"steps = "<<steps<<endl;
    //printWordTree(word_tree);
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

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
