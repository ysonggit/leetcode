#include <gtest/gtest.h>
#include "utils.h"
using namespace std;
/*
  for the nodes with the same horizontal distance, print the top one
 */
// can use pair instead also
// typedef pair<int, TreeNode*> NodeHD;
struct NodeHD{
    TreeNode * node;
    int hr_dist;
    NodeHD(TreeNode * n, int hd) {
        node = n;
        hr_dist = hd;
    }
};

void topView(TreeNode * root){
    if(root==NULL) return;
    queue<NodeHD*> Q;
    map<int, TreeNode*> hd_node;// map sorts its elements by keys
    Q.push(new NodeHD(root, 0));
    while(!Q.empty()){
        NodeHD * cur = Q.front();
        Q.pop();
        if(hd_node.find(cur->hr_dist)==hd_node.end() ){
            hd_node[cur->hr_dist] = cur->node;
        }
        if(cur->node->left != NULL){
            Q.push(new NodeHD(cur->node->left, cur->hr_dist-1));
        }
        if(cur->node->right != NULL){
            Q.push(new NodeHD(cur->node->right, cur->hr_dist+1));
        }
    }
    for(auto it = hd_node.begin(); it !=hd_node.end(); ++it){
        cout<<it->second->val<<" ";
    }
    cout<<endl;
}

TEST(TopView, I){
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
    cout<<"desired top view : 2 1 3 6\n";
    cout<<"actual top view : ";
    topView(nodes[0]);
}

TEST(TopView, II){
    /*      1
           /  \
          2    3
           \  / \
            47   8
             \
              5
               \
                6
    */
    string vals="{1,2,3,9,4,7,8,#,#,#,5,#,#,0,#,#,6}";
    vector<TreeNode*> nodes;
    treeInitializer(nodes, vals);
    printTree(nodes[0], 2);
    cout<<"desired top view : 9 2 1 3 8\n";
    cout<<"actual top view : ";
    topView(nodes[0]);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


