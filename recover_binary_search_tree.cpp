#include "utils.h"

using namespace std;
   /*
     idea: inorder traversal, find two elements in wrong order
           if there is only one wrong swap, means two elements are close to each other:
                   3
                  / \
                 1   5
                /   / \
               2   4   6
               in-order: 213456
               swap 2 and 1
           if there are two wrong swaps, means two elements are not close
                   3
                  / \
                 2   5
                /   / \
               1    6  4
               in-order: 123654
               swap 6 and 4
            Rule: the 1st num used for swap is always the first element in wrong order
                  the 2nd num used for swap is the last element in the last wrong order
               
     Morris Inorder Traversal
        1. Initialize current as root 
        2. While current is not NULL
            If current does not have left child
                a) Print current’s data
                b) Go to the right, i.e., current = current->right
            Else
                find the inorder predecessor of current node's left subtree 
                (which is either the rightmost node of left subtree or the  rightmost node whose rightchid is current node)
                If the predecessor->right child is null
                    a) Assign current to the right child of the predecessor in current's left subtree
                    b) Go to this left child, i.e., current = current->left
                Else
                    a) Make right child of the predecessor NULL 
                    b) Print current node's value
                    c) Go to right child of current node, i.e. current = current->right
    */

TreeNode * inorderPredecessor(TreeNode * root, TreeNode * cur){
    if(root==NULL) return root;
    if(root->right==NULL || root->right == cur){
        return root;
    }
    return inorderPredecessor(root->right, cur);
}

void recoverTree(TreeNode* root){
    if(root==NULL) return;
    TreeNode *cur = root, *pre=NULL;
    TreeNode *first=NULL, *second=NULL;
    int count = 0;
    while(cur != NULL){
        if(cur->left == NULL){
            if(count==0){
                if(cur->right !=NULL && cur->val > cur->right->val){
                    first = cur;
                    count++;
                }
                if(pre!= NULL && cur->val < pre->val){
                    first = pre;
                    count++;
                }
            }
            if(count>0){
                if(cur->right !=NULL && cur->val > cur->right->val){
                    second = cur->right;
                    count++;
                }
                if(pre!= NULL && cur->val < pre->val){
                    second = cur;
                    count++;
                }
            }
            pre = cur;
            cur=cur->right;
        }else{
            TreeNode * pred = inorderPredecessor(cur->left, cur);
            if(pred->right == NULL){
                pred->right = cur;
                cur = cur->left;
            }else{
                pred->right = NULL;
                if(count==0){
                    if(cur->right !=NULL && cur->val > cur->right->val){
                        first = cur;
                        count++;
                    }
                    if(pre!= NULL && cur->val < pre->val){
                        first = pre;
                        count++;
                    }
                }
                if(count>0){
                    if(cur->right !=NULL && cur->val > cur->right->val){
                        second = cur->right;
                        count++;
                    }
                    if(pre!= NULL && cur->val < pre->val){
                        second = cur;
                        count++;
                    }
                }
                pre = cur;
                cur = cur->right;
            }
        }
    }
    // swap first and second
    if(first!=NULL && second != NULL){
        swap(first->val, second->val);
    }
}

int main(int argc, char *argv[])
{
    string vals = "{3,1,5,2,#,4,6}";
    vector<TreeNode*> nodes;
    treeInitializer(nodes, vals);
    printTree(nodes[0], 2);
    cout<<"-----------recover--------------\n";
    recoverTree(nodes[0]);
    printTree(nodes[0], 2);
    cout<<"=================================\n";
    string vals1 = "{3,2,5,1,#,6,4}";
    vector<TreeNode*> nodes1;
    treeInitializer(nodes1, vals1);
    printTree(nodes1[0], 2);
    cout<<"-----------recover--------------\n";
    recoverTree(nodes1[0]);
    printTree(nodes1[0], 2);
    cout<<"=================================\n";
    string vals2 = "{2,#,3,1}";
    vector<TreeNode*> nodes2;
    treeInitializer(nodes2, vals2);
    printTree(nodes2[0], 2);
    cout<<"-----------recover--------------\n";
    recoverTree(nodes2[0]);
    printTree(nodes2[0], 2);
    cout<<"=================================\n";
    string vals3 = "{2,3,1}";
    vector<TreeNode*> nodes3;
    treeInitializer(nodes3, vals3);
    printTree(nodes3[0], 3);
    cout<<"-----------recover--------------\n";
    recoverTree(nodes3[0]);
    printTree(nodes3[0], 2);
    return 0;
}


