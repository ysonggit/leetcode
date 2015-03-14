#include <gtest/gtest.h>
#include "utils.h"
using namespace std;
/*
  recursive version
  9ms

bool mirror(TreeNode* left_child, TreeNode* right_child){
    if(!left_child && !right_child) return true;
    if(!left_child || !right_child) return false;
    if(left_child->val != right_child->val) return false;
    return mirror(left_child->left, right_child->right) && mirror(left_child->right, right_child->left); 
}

bool isSymmetric(TreeNode *root) {
    if(!root) return true;
    return mirror(root->left, root->right);
}
*/
/*
  iterative version: level order traversal
  9ms
*/

bool isSymmetric(TreeNode *root) {
    if(!root) return true;
    if(!root->left && !root->right) return true;
    vector<TreeNode*> cur_level, nex_level;
    cur_level.push_back(root);
    while(!cur_level.empty() ){
        TreeNode * cur = cur_level.back();
        cur_level.pop_back();
        if(cur){
            nex_level.push_back(cur->left);
            nex_level.push_back(cur->right);
        }
        if(cur_level.empty()){
            cur_level.swap(nex_level);
            // validate current level vals
            int n =  cur_level.size();
            for(auto i=0; i < n/2; ++i){
                if(cur_level[i] && cur_level[n-i-1]){
                    if(cur_level[i]->val != cur_level[n-i-1]->val) return false;
                }
                if(!cur_level[i] && !cur_level[n-i-1]) continue;
                if(!cur_level[i] || !cur_level[n-i-1]) return false;
            }
        }
    }
    return true;
}

TEST(SymmetricTree, I){
    vector<TreeNode*> nodes;
    string vals("1,2,2,#,3,#,3");
    treeInitializer(nodes, vals);
    printTree(nodes[0], 2);
    bool res = false;
    ASSERT_EQ(res, isSymmetric(nodes[0]));
}

TEST(SymmetricTree, II){
    vector<TreeNode*> nodes;
    string vals("1,2,2,3,4,4,3");
    treeInitializer(nodes, vals);
    printTree(nodes[0], 2);
    bool res = true;
    ASSERT_EQ(res, isSymmetric(nodes[0]));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}