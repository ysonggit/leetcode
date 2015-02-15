#include "utils.h"
#include <gtest/gtest.h>

using namespace std;
/*
  idea : BFS
  it is a tree, so no need to mark visited node
 */
vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int> > vals;
    if(root == NULL) return vals;
    queue<TreeNode*> current_level, next_level;
    current_level.push(root);
    vector<int> current_level_vals;
    while(!current_level.empty()){
        TreeNode * cur = current_level.front();
        current_level.pop();
        current_level_vals.push_back(cur->val);
        if(cur->left != NULL){
            next_level.push(cur->left);
        }
        if(cur->right != NULL){
            next_level.push(cur->right);
        }
        if(current_level.empty()){
            current_level.swap(next_level);
            vals.push_back(current_level_vals);
            current_level_vals.clear();
        }
    }
    return vals;
}

TEST(LevelOrderTraversal, I){
    string vals = "{3,9,20,#,#,15,7}";
    vector<TreeNode*> nodes;
    treeInitializer(nodes, vals);
    print2DVector(levelOrder(nodes[0]));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



