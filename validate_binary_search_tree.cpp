#include "utils.h"
#include <gtest/gtest.h>

using namespace std;
/*
  idea
  1) inorder traverse the tree, check if increasing
     during the traversal, maintains the max value
     if current val is less than the max value, then false
     be careful of dealing with overflow 
     19ms
     
  bool isValidBST(TreeNode *root) {
    if(root==nullptr) return true;
    if(root->left == NULL && root->right ==NULL) return true;
    stack<TreeNode*> parent_stack;
    TreeNode * cur = root;
    long max_val = LONG_MIN;
    while(!parent_stack.empty() || cur!=nullptr){
        if(cur!=nullptr){
            parent_stack.push(cur);
            cur = cur->left;
        }else{
            cur = parent_stack.top();
            parent_stack.pop();           
            if(cur->val <= max_val){
                return false;
            }else{
                max_val = cur->val;
            }
            cur = cur->right;
        }
    }
    return true;
    }
*/
//  recursive version 18ms
bool inorder(TreeNode * node, TreeNode * & prev){
    if(node==NULL) return true;
    if(!inorder(node->left, prev) ) return false;
    if(prev!=NULL && node->val <= prev->val) return false;
    prev = node;
    return inorder(node->right, prev);
}

bool isValidBST(TreeNode * root){
    TreeNode * prev = NULL;
    return inorder(root, prev);
}

TEST(BST, I){
    vector<TreeNode*> nodes;
    string vals = "{1,#,2,3}";
    treeInitializer(nodes, vals);
    bool res = false;
    ASSERT_EQ(res, isValidBST(nodes[0]));
}

TEST(BST, II){
    vector<TreeNode*> nodes;
    string vals = "{-2147483648,#,2147483647}";
    treeInitializer(nodes, vals);
    bool res = true;  
    ASSERT_EQ(res, isValidBST(nodes[0]));
}

TEST(BST, III){
    vector<TreeNode*> nodes;
    string vals = "{0,-1}";
    treeInitializer(nodes, vals);
    bool res = true;  
    ASSERT_EQ(res, isValidBST(nodes[0]));
}

TEST(BST, IV){
    vector<TreeNode*> nodes;
    string vals = "{1,1}";
    treeInitializer(nodes, vals);
    bool res = false;  
    ASSERT_EQ(res, isValidBST(nodes[0]));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

