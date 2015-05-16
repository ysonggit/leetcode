#include <gtest/gtest.h>
#include "utils.h"
#include <unordered_map>

using namespace std;

class WordDictionary {
public:
    struct TrieNode{
        bool isword;
        unordered_map<char, TrieNode*> children;
        TrieNode(){
            isword = false;
        }
    };
    TrieNode * root;

    WordDictionary(){
        root = new TrieNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode * cur = root;
        if(cur==NULL|| word.empty()) return;
        for(int i=0; i<word.length(); i++){
            char c = word[i];
            if(cur->children.find(c)==cur->children.end()){
                cur->children[c] = new TrieNode();
            }
            cur = (cur->children[c]);
        }
        cur->isword= true;
    }

    bool search(TrieNode * node, string word){
        if(word.empty()){
            if(node==NULL) return true;
            if(node->isword) return true;
            if(node->children.size()>0) return false;
        }
        TrieNode * cur = node;
        for(int i=0; i<word.length(); i++){
            char c = word[i];
            if(c!='.'){
                if(cur->children.find(c) == cur->children.end()) return false;
                cur= cur->children[c];
            }else{
                // match each children
                string wd = word.substr(i+1);
                for(auto it = cur->children.begin(); it != cur->children.end();++it) {
                    if(search (it->second, wd)) return true;
                }
                return false;
            }
        }
        return cur->isword;
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(root, word);
    }
};

TEST(Dict, I){
    WordDictionary wd;
    string s = "word";
    string t = "w..d";
    wd.addWord(s);
    bool res = true;
    ASSERT_EQ(res, wd.search(t));
}

TEST(Dict, II){
    WordDictionary wd;
    string s = "word";
    string t = "....";
    wd.addWord(s);
    bool res = true;
    ASSERT_EQ(res, wd.search(t));
}

TEST(Dict, III){
    WordDictionary wd;
    string s = "word";
    string t = "w..";
    wd.addWord(s);
    bool res = false;
    ASSERT_EQ(res, wd.search(t));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
