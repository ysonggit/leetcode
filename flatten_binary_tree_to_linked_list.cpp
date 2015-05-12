#include <gtest/gtest.h>
#include "utils.h"

using namespace std;
/*
idea: stack
         1
        / \
       2   5
      / \   \
     3   4   6
  
  push 1 to stack
  pop 1
  push 5 to stack 
  push 2 to stack
  set 1->left to null
  set 1->right to stack.top (stack: 2,5)
  
  pop 2
  push 4 to stack
  push 3 to stack
  set 2->left to null
  set 2->right to stack top (stack: 3,4,5)
  
  pop 3
  set 3->left null
  set 3->right stack top (stack: 4,5)
  
  pop 4
  set 4->left null
  set 4->right stack top (stack: 5)
  
  pop 5
  push 6 to stack
  set 5->left = null
  set 5->right = stack top (stack: 6)
  
  pop 6
  set both left and right null (stack: empty)
  
void flatten(TreeNode *root) {
    if(!root) return ;
    stack<TreeNode*> to_be_flatten;
    to_be_flatten.push(root);
    while(!to_be_flatten.empty()){
        TreeNode * cur = to_be_flatten.top();
        to_be_flatten.pop();
        if(cur->right) to_be_flatten.push(cur->right);
        if(cur->left) to_be_flatten.push(cur->left);
        cur->left = nullptr;
        if(!to_be_flatten.empty()) cur->right = to_be_flatten.top();
    }
}
*/
TreeNode * helper(TreeNode *& root){
    if(root == NULL) return NULL;
    TreeNode * left = helper(root->left);
    TreeNode * right = helper(root->right);
    TreeNode * left_tail = left;
    while(left_tail && left_tail->right) left_tail= left_tail->right;
    if(left_tail) left_tail->right = right;
    root->left = NULL;
    root->right = left ? left : right;
    return root;
}

void flatten(TreeNode *root){
    helper(root);
}

TEST(Flatten, I){
    vector<TreeNode*> nodes;
    string vals = "{1,2,5,3,4,#,6}";
    treeInitializer(nodes, vals);
    printTree(nodes[0], 2);
    flatten(nodes[0]);
    cout<<"========== Flatten Binary Tree =========="<<endl;
    printTree(nodes[0], 2);
}


TEST(Flatten, II){
    vector<TreeNode*> nodes;
    string vals = "{1,#,2,3}";
    treeInitializer(nodes, vals);
    printTree(nodes[0], 2);
    flatten(nodes[0]);
    cout<<"========== Flatten Binary Tree =========="<<endl;
    printTree(nodes[0], 2);
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



