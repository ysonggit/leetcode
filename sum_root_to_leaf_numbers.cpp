#include "utils.h"
#include <gtest/gtest.h>

using namespace std;

/*
  idea DFS
     1
    / \
   2   3
   represents 12, 13
   how about following tree?
       1
      / \
     2   3
    / \ 
   4   5
   represents 124 125 13
    for a node, if it has children
    int dfs(node, cur_sum){
       if node is null , return 0;
       cur_sum = cur_sum * 10  + node.val
       return dfs(node.left, cur_sum) + dfs(node.right, cur_sum)
    }
    problem : overflow? what is the max depth of the tree
*/

int dfs(TreeNode * node, int cur_sum){
    if(node == NULL)  return 0;
    cur_sum = cur_sum * 10 + node->val;
    if(node->left == NULL && node->right == NULL) return cur_sum;
    return dfs(node->left, cur_sum) + dfs(node->right, cur_sum);
}

int sumNumbers(TreeNode *root) {
    return dfs(root, 0);
}

TEST(Sum, I){
    string vals = "{1,2,3}";
    vector<TreeNode*> nodes;
    treeInitializer(nodes, vals);
    int res = 25;
    ASSERT_EQ(res, sumNumbers(nodes[0]));
}

TEST(Sum, II){
    string vals = "{1,2,3,4,5}";
    vector<TreeNode*> nodes;
    treeInitializer(nodes, vals);
    int res = 262;
    ASSERT_EQ(res, sumNumbers(nodes[0]));
}

TEST(Sum, III){
    string vals = "{1}";
    vector<TreeNode*> nodes;
    treeInitializer(nodes, vals);
    int res = 1;
    ASSERT_EQ(res, sumNumbers(nodes[0]));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


