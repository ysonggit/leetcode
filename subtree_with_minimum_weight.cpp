#include <gtest/gtest.h>
#include "utils.h"
using namespace std;
/**
   the weight of a tree = sum of weight of all node in the tree.
   Weight of node  = value of node * level of the node in the tree
   source : mitbbs
 */

void getNodesWeights(TreeNode * root,  unordered_map<TreeNode*, int> & nodes_weights){
    if(root==NULL) return;
    queue<TreeNode*> Q;
    Q.push(root);
    int curr_level=1;
    int next_level=0;
    int level=1;
    while(!Q.empty()){
        auto cur = Q.front();
        nodes_weights[cur] = (cur->val)*level;
        Q.pop();
        curr_level--;
        if(cur->left!= NULL){
            Q.push(cur->left);
            next_level++;
        }
        if(cur->right!=NULL){
            Q.push(cur->right);
            next_level++;
        }
        if(curr_level==0){
            level++;
            curr_level= next_level;
            next_level=0;
        }
    }
}
unordered_map<TreeNode*, int> trees_weights;

int getTreeWeight(TreeNode * root, unordered_map<TreeNode*, int> & nodes_weights){
    if(root==NULL) return 0;
    if(root->left ==NULL && root->right==NULL) {
        trees_weights[root] = nodes_weights[root];
        return nodes_weights[root];
    }
    if(trees_weights.find(root)!= trees_weights.end()) return trees_weights[root];
    int tw = getTreeWeight(root->left, nodes_weights) + getTreeWeight(root->right, nodes_weights);
    trees_weights[root] = tw;
    return tw;
}

TreeNode * subtreeWithMinWeight(TreeNode * root){
    if(root==NULL ) return NULL;
    // key is the root of a subtree, value is the weight of subtree of corresponding root
    unordered_map<TreeNode*, int> nodes_weights;
    getNodesWeights(root,  nodes_weights);
    getTreeWeight(root, nodes_weights);
    auto it=trees_weights.begin();
    auto min_weight=it->second;
    auto root_of_min_weight_tree = it->first;
    advance(it, 1);
    for(; it!= trees_weights.end(); ++it){
        if(it->second < min_weight){
            min_weight=it->second;
            root_of_min_weight_tree = it->first;
        }
    }
    return root_of_min_weight_tree;
}

TEST(MinWeightSubTree, I){
    string vals="{8,7,6,2,-4,-5,#,10,#,9,#,#,13}";
    vector<TreeNode*> nodes;
    treeInitializer(nodes, vals);
    printTree(nodes[0],2);
    TreeNode * s=subtreeWithMinWeight(nodes[0]);
    cout<<"------------ Subtree With Minimum Weight ------------\n";
    printTree(s, 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}