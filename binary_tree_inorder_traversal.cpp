#include <gtest/gtest.h>
#include "utils.h"

using namespace std;

/*
  idea:
  0, basic recursive version
  inorder(root){
    if root is null return
    inorder(root->left)
    visit(root->val)
    inorder(root->right)
  }
  1, O(n) time O(1) space
  2, iterative version O(n) time O(n) space
 */
vector<int> inorderTraversal(TreeNode *root) {
    vector<int> vals; 
    if(root == NULL) return vals;
    stack<TreeNode*> parentStack;
    TreeNode * cur = root;
    while(!parentStack.empty() || cur != NULL){
        if(cur != NULL){
            parentStack.push(cur);
            cur = cur->left;
        }else{
            cur = parentStack.top();
            parentStack.pop();
            vals.push_back(cur->val);
            cur = cur->right;
        }
    }
    return vals;
}

TEST(Inorder, I){
    vector<TreeNode*> nodes;
    string vals = "{1,#,2,3}";
    treeInitializer(nodes, vals);
    printVector(inorderTraversal(nodes[0]));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
