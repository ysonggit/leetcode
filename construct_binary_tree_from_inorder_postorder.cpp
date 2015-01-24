#include "utils.h"

using namespace std;

/*
   preorder : root appears at the first position
   postorder : root appears at the last position
   inoder : root appears in the middle
 */

TreeNode *buildTreeRecur(vector<int> &inorder, vector<int> &postorder, int post_start, int post_end, int in_start, int in_end, unordered_map<int, int>& inorder_pos){
    TreeNode * root = new TreeNode(postorder[post_end]);
    // base case
    if(post_start == post_end && in_start == in_end) return root;
    // locate the pos of root in the inorder list
    int in_pos = inorder_pos[root->val];
    // then in the inorder list, we can get  # of elements for construct left/right subtree
    // in the inorder in_start ...in_pos-1 are the values of the left sub tree (in_pos-in_start)
    //                in_pos+1 ... in_end are the values of the right sub tree (in_end-in_pos)

    // in the postorder, use post_end-(in_end-in_pos) ... post_end-1 elements to construct the right sub tree
    //                  use post_start.. post_start+(in_pos-in_start)-1 elements for the left sub tree
    if(in_pos-in_start>0){
        root->left = buildTreeRecur(inorder,postorder,  post_start, post_start+in_pos-in_start-1, in_start, in_pos-1, inorder_pos);
    }
    if(in_end- in_pos>0){
        root->right = buildTreeRecur(inorder, postorder,  post_end-(in_end-in_pos), post_end-1, in_pos+1, in_end, inorder_pos);
    }
    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if(postorder.size()==0 || inorder.size()==0) return nullptr;
    unordered_map<int, int> inorder_pos;
    for(int i=0; i<inorder.size(); i++){
        inorder_pos.insert(unordered_map<int,int>::value_type(inorder[i], i));
    }
    return buildTreeRecur(inorder, postorder, 0, postorder.size()-1, 0, inorder.size()-1, inorder_pos);
}

int main(int argc, char *argv[]){
    vector<int> inorder ={1,2};
    vector<int> postorder ={2,1};
    TreeNode * t = buildTree(inorder, postorder);
    printTree(t, 2);
    return 0;
}
