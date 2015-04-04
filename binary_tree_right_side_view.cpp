#include <gtest/gtest.h>
#include "utils.h"
using namespace std;

vector<int> rightSideView(TreeNode *root) {
    if(root==NULL) return vector<int>();
    vector<int> vals;
    deque<TreeNode*> Q;
    Q.push_back(root);
    vals.push_back(root->val);
    int curr_level = 1, next_level = 0;
    while (!Q.empty()){
        TreeNode * cur = Q.front();
        Q.pop_front();
        curr_level--;
        if(cur->left != NULL) {
            Q.push_back(cur->left);
            next_level++;
        }
        if(cur->right != NULL){
            Q.push_back(cur->right);
            next_level++;
        }
        if(curr_level==0){
            swap(curr_level, next_level);
            if(!Q.empty()) vals.push_back((Q.back())->val);
        }
    }
    return vals;
}

TEST(BT, I){
    string vals = "{1,2,3,#,5,#,4}";
    vector<TreeNode*> nodes;
    treeInitializer(nodes, vals);
    vector<int> res = rightSideView(nodes[0]);
    cout<<"Ideal output : 1, 3, 4\nActual output: ";
    printVector(res);
}

TEST(BT, II){
    string vals = "{1,2,3,5}";
    vector<TreeNode*> nodes;
    treeInitializer(nodes, vals);
    vector<int> res = rightSideView(nodes[0]);
    cout<<"Ideal output : 1, 3, 5\nActual output: ";
    printVector(res);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

