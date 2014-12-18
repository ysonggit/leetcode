#include "utils.h"

using namespace std;
/*
  For every node in given tree, math sum of paths can be obtained by
  local_max(node) is the sum across current node to its parent
  it will be returned to its parent 
  local_max(node) =  max(node + leftchild, node + rightchild, node)
  global_max(node) is the max sum among all traversed paths, including ARC-like path
  global_max(node) = max(leftchild + rightchild + node, local_max, global_max)

  Given a binary tree:
            1
           / \
          2   3
         / \ / \
        4  5 6  7

  For node 2, local_max = max(2, 2+4, 2+5) = 7
              global_max = max(global_max, max(7, 2+4+5))
 */
int pathSum(TreeNode * node, int & globalmax){
    if(node== nullptr) return 0;
    int leftpath = pathSum(node->left, globalmax)+node->val;
    int rightpath = pathSum(node->right, globalmax)+node->val;
    int arcpath = leftpath + rightpath - node->val;
    int localmax = max(max(leftpath, rightpath), node->val);
    globalmax = max(globalmax, max(localmax, arcpath));
    return localmax;
}

int maxPathSum(TreeNode *root) {
    if(root==NULL) return 0;
    int globalmax = INT_MIN; //Be careful: can not initialize as 0
    pathSum(root, globalmax);
    return globalmax;
}

int main(int argc, char *argv[]){
    string vals = "{1,2,3,4,5,6,7}";
    vector<TreeNode*> nodes;
    treeInitializer(nodes, vals);
    //printTree(nodes[0], 2);
    cout<<maxPathSum(nodes[0])<<endl;
    TreeNode * n = new TreeNode(-3);
    cout<<maxPathSum(n)<<endl;
    return 0;
}

