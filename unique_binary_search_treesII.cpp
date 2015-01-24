#include "utils.h"

using namespace std;

/*divide and conquer
  for 1,2,3...i,.. n
  if root is i, connect its 
  left subtree composed of [1, i-1] and
  right subtree composed of [i+1, n]

  for each root i, there are 
  
  coding key: how to store a possible BST?

  if n==0, return [{}] : empty tree contains a null root node
 */

void dfs(vector<TreeNode *> & subtree, int left, int right){
    if(left>right){
        subtree.push_back(nullptr);// tricky, even 0 children in the subtree, represent as one null child in the subtree 
        return;
    }
    for(int i=left; i<=right; i++){
        vector<TreeNode*> lefttree;
        dfs(lefttree, left, i-1);
        vector<TreeNode*> righttree;
        dfs(righttree, i+1, right);
        for(int j=0; j<lefttree.size(); j++){
            for(int k=0; k<righttree.size(); k++){
                TreeNode * n = new TreeNode(i);
                n->left = lefttree[j];
                n->right = righttree[k];
                subtree.push_back(n);
            }
        }
    }
}

vector<TreeNode *> generateTrees(int n) {
    vector<TreeNode *>  alltrees;
    dfs(alltrees, 1, n);
    return alltrees;
} 

int main(int argc, char *argv[]){
    vector<TreeNode*> bst = generateTrees(3);
    for(TreeNode * n : bst){
        printTree(n,2);
        cout<<"\n------------------\n";
    }
    return 0;
}
