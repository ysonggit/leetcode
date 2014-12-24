#include "utils.h"

using namespace std;

/*
   Very similar to reverse linked list
   For example, represent a tree
      1
     / \
    2   3
   / \
  4   5

  as

   --> 3
   |
 1      --> 5
   |    |
   --> 2
        |
        --> 4

   The result is

        3
        ^
  1     |    5
   |    |    ^
    <-- 2    |
        |    |
         <-- 4

   Idea: // save copies of current node's parent and right sibling
         left_child = cur->left 
         right_child = cur->right
         // flip 
         cur -> left = right_sibling
         cur -> right = parent
         // go to next round
         parent = cur
         right_sibling = right_child
         cur = left_child
*/

TreeNode *upsideDownBinaryTree(TreeNode *root) {
    if(!root || (!root->left && !root->right)) return root;
    TreeNode * parent = nullptr;
    TreeNode * right_sibling = nullptr;
    TreeNode * cur = root;
    TreeNode * left_child;
    TreeNode * right_child;
    while(cur != nullptr){
        left_child = cur ->left;
        right_child = cur->right;
        cur -> left = right_sibling;
        cur -> right = parent;
        parent = cur;
        right_sibling = right_child;
        cur = left_child;
    }
    return parent;
}

int main(int argc, char *argv[]){
    string vals = "{1,2,3,4,5}";
    vector<TreeNode*> nodes;
    treeInitializer(nodes, vals);
    printTree(nodes[0], 2);
    cout<<"-------------------\n";
    TreeNode * n = upsideDownBinaryTree(nodes[0]);
    printTree(n, 2);
    return 0;
}

