#include <gtest/gtest.h>
#include "utils.h"
using namespace std;
/**
 * This method will be invoked first, you should design your own algorithm 
 * to serialize a binary tree which denote by a root node to a string which
 * can be easily deserialized by your own "deserialize" method later.
 */

void preorder(TreeNode *root, string & data){
    if(root==NULL) {
        if(!data.empty()){
            data += string(",$");
        }
        return;
    }
    stringstream ss;
    ss << root->val;
    if(data.empty()){
        data += ss.str();       
    }else{
        data += string(",") + ss.str();
    }
    preorder(root->left, data);
    preorder(root->right, data);
}

string serialize(TreeNode *root) {
    string data;
    preorder(root, data);
    return data;
}

/**
 * This method will be invoked second, the argument data is what exactly
 * you serialized at method "serialize", that means the data is not given by
 * system, it's given by your own serialize method. So the format of data is
 * designed by yourself, and deserialize it here as you serialize it in 
 * "serialize" method.
 */
void helper(string & vals, TreeNode *& parent){
    if(vals.empty() ) return;
    auto first_comma = vals.find_first_of(",");
    if(first_comma == string::npos){
        // be careful, the last position has no comma
        string node_val = vals;
        if(node_val=="$") return;
    }else{
        string node_val= vals.substr(0, first_comma);
        vals = vals.substr(first_comma+1);
        if(node_val!="$") {
            parent = new TreeNode(stoi(node_val));
            helper(vals, parent->left);
            helper(vals, parent->right);
        }
    }
}

TreeNode *deserialize(string data) {
    TreeNode* root = NULL;
    helper(data, root);
    return root;
}

TEST(SDBT, I){
    string vals = "1,2,3,#,#,#,4";
    vector<TreeNode*> nodes;
    treeInitializer(nodes, vals);
    string data = serialize(nodes[0]);
    cout<<data<<endl;
    TreeNode * root = deserialize(data);
    printTree(root, 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

