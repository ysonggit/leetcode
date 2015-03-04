#include <gtest/gtest.h>
#include "utils.h"

using namespace std;
/*
  for each node, check its left subtree height and right subtree height
  if height difference >=2
  return false
  otherwise recursively check if the subtree rooted at left node is balanced
            recursively check if the subtree rooted at right node is balanced
 */
int treeHeight(TreeNode * root){
    if(!root) return 0;
    return max(treeHeight(root->left), treeHeight(root->right))+1;
}

bool isBalanced(TreeNode * root){
    if(!root) return true;
    int height_left_subtree = treeHeight(root->left);
    int height_right_subtree = treeHeight(root->right);
    if(abs(height_left_subtree-height_right_subtree)>=2) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}

TEST(BalancedTree, I){
    vector<TreeNode*> nodes;
    string vals = "{1,2,5,3,4,#,6}";
    treeInitializer(nodes, vals);
    printTree(nodes[0], 2);
    bool res = true;
    ASSERT_EQ(res, isBalanced(nodes[0]));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


