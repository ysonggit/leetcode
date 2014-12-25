#include "utils.h"

using namespace std;

/*
   preorder : root appears at the first position
   inoder : root appears in the middle
 */

TreeNode *buildTreeRecur(vector<int> &preorder, vector<int> &inorder, int pre_start, int pre_end, int in_start, int in_end){
    TreeNode * root = new TreeNode(preorder[pre_start]);
    // base case
    if(pre_start == pre_end && in_start == in_end) return root;
    // locate the pos of root in the inorder list
    int in_pos = -1;
    for(int i=in_start; i<=in_end; i++){
        if(inorder[i]==preorder[pre_start]){
            in_pos = i;
            break;
        }
    }
    // in the inorder in_start ...in_pos-1 are the values of the left sub tree (in_pos-in_start)
    //                in_pos+1 ... in_end are the values of the right sub tree

    // in the preorder, use pre_start+1 ... pre_start+in_pos-in_start elements to construct the left sub tree
    //                  use pre_start+in_pos-in_start+1 ... pre_end elements for the right sub tree
    if(in_pos-in_start>0){
        root->left = buildTreeRecur(preorder, inorder, pre_start+1, pre_start+in_pos-in_start, in_start, in_pos-1);
    }
    if(in_end- in_pos>0){
        root->right = buildTreeRecur(preorder, inorder,  pre_start+in_pos-in_start+1, pre_end, in_pos+1, in_end);
    }
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if(preorder.size()==0 || inorder.size()==0) return nullptr;
    return buildTreeRecur(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
}

int main(int argc, char *argv[]){
    int pre[]={1,2,4,7,3,5,6,8};
    int in[]={4,7,2,1,5,3,8,6};
    vector<int> preorder(pre, pre+sizeof(pre)/sizeof(*pre));
    vector<int> inorder(in, in+sizeof(in)/sizeof(*in));
    TreeNode * t = buildTree(preorder, inorder);
    printTree(t, 2);
    return 0;
}
