#include "utils.h"

using namespace std;

/*
   preorder : root appears at the first position
   inoder : root appears in the middle
 */

TreeNode *buildTreeRecur(vector<int> &preorder, vector<int> &inorder, int pre_start, int pre_end, int in_start, int in_end, unordered_map<int,int> & inorder_pos){
    TreeNode * root = new TreeNode(preorder[pre_start]);
    // base case
    if(pre_start == pre_end && in_start == in_end) return root;
    // locate the pos of root in the inorder list
    int in_pos = inorder_pos[root->val];
    // in the inorder in_start ...in_pos-1 are the values of the left sub tree (in_pos-in_start)
    //                in_pos+1 ... in_end are the values of the right sub tree

    // in the preorder, use pre_start+1 ... pre_start+in_pos-in_start elements to construct the left sub tree
    //                  use pre_start+in_pos-in_start+1 ... pre_end elements for the right sub tree
    if(in_pos-in_start>0){
        root->left = buildTreeRecur(preorder, inorder, pre_start+1, pre_start+in_pos-in_start, in_start, in_pos-1, inorder_pos);
    }
    if(in_end- in_pos>0){
        root->right = buildTreeRecur(preorder, inorder,  pre_start+in_pos-in_start+1, pre_end, in_pos+1, in_end, inorder_pos);
    }
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if(preorder.size()==0 || inorder.size()==0) return nullptr;
    unordered_map<int,int> inorder_pos;
    for(int i=0; i<inorder.size(); i++){
        inorder_pos[inorder[i]]=i;
    }
    return buildTreeRecur(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1, inorder_pos);
}

int main(int argc, char *argv[]){
    vector<int> preorder ={1,2,4,7,3,5,6,8};
    vector<int> inorder={4,7,2,1,5,3,8,6};
    TreeNode * t = buildTree(preorder, inorder);
    printTree(t, 2);
    return 0;
}
