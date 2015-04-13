#include <gtest/gtest.h>
#include "utils.h"
using namespace std;
/*
  Given a Binary Tree, we need to print the bottom view from left to right.
  A node x is there in output if x is the bottommost node at its horizontal distance.
  Horizontal distance of left child of a node x is equal to horizontal distance of x minus 1,
  and that of right child is horizontal distance of x plus 1.
 */

struct NodeHD{
    TreeNode * node;
    int hr_dist;
    NodeHD(TreeNode *n, int hd){
        node = n;
        hr_dist = hd;
    }
};

void bottomView(TreeNode * root){
    if(root==NULL) return;
    map<int, TreeNode*> hd_node;
    queue<NodeHD*> Q;
    Q.push(new NodeHD(root, 0));
    while(!Q.empty()){
        NodeHD * cur = Q.front();
        Q.pop();
        hd_node[cur->hr_dist] = cur->node;
        if(cur->node->left != NULL){
            Q.push(new NodeHD(cur->node->left, cur->hr_dist-1));
        }
        if(cur->node->right != NULL){
            Q.push(new NodeHD(cur->node->right, cur->hr_dist+1));
        }
    }
    for(auto it = hd_node.begin(); it!= hd_node.end(); ++it){
        cout<<it->second->val<<" ";
    }
    cout<<endl;
}

TEST(BottomView, I){
    /*      1
           /  \
          2    3
           \
            4
             \
              5
               \
                6
    */
    string vals="{1,2,3,#,4,#,#,#,5,#,6}";
    vector<TreeNode*> nodes;
    treeInitializer(nodes, vals);
    printTree(nodes[0], 2);
    cout<<"desired bottom view : 2 4 5 6\n";
    cout<<"actual bottom view : ";
    bottomView(nodes[0]);
}

TEST(BottomView, II){
    /*      1
           /  \
          2    3
         / \  / \
        9   47   8
             \  /
              50
               \
                6
    */
    string vals="{1,2,3,9,4,7,8,#,#,#,5,#,#,0,#,#,6}";
    vector<TreeNode*> nodes;
    treeInitializer(nodes, vals);
    printTree(nodes[0], 2);
    cout<<"desired bottom view : 9 2 7 0 6\n";
    cout<<"actual bottom view : ";
    bottomView(nodes[0]);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
