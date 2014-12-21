#include "utils.h"
using namespace std;

///////////////////////////////////////////////////////////
//              Functions for Linked List               //
///////////////////////////////////////////////////////////
void printList(ListNode * head){
    ListNode * cur = head;
    while(cur!=NULL){
        std::cout<<cur->val<<" -> ";
        cur = cur->next;
    }
    std::cout<<"NULL"<<std::endl;
}
///////////////////////////////////////////////////////////
//              Functions for Binary Tree                //
///////////////////////////////////////////////////////////
std::vector<std::string> split(const std::string &s, char delim) {
    std::istringstream ss(s);
    std::string item;
    std::vector<std::string> tokens;
    while (std::getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}

// input string contains brackets "{}"
void treeInitializer(std::vector<TreeNode *> & nodes, const std::string & vals){
    //1. pass by left & right brackets {}
    std::size_t left_idx = vals.find("{");
    std::size_t right_idx = vals.find("}"); // indices of {}
    // truncate the original string by copying only values
    std::string values = vals.substr(left_idx+1, right_idx-left_idx-1);
    if(values.length()==0) return;
    std::vector<std::string> tokens = split(values, ',');
    for(int i=0; i<tokens.size(); i++){
        TreeNode * n = NULL;
        std::string str = tokens[i];
        if(str.find("#") == std::string::npos){
            int val = stoi(str);
            n  = new TreeNode(val);
        }
        nodes.push_back(n);
    }
    bool left_child = true;
    std::queue<TreeNode*> q;
    q.push(nodes[0]);
    TreeNode * cur = NULL;
    for(int i=1; i< nodes.size(); i++){
        TreeNode * n = nodes[i];
        if(left_child){
            cur = q.front();
            q.pop();
            left_child = false;
            cur->left = n;
        }else{
            cur->right = n;
            left_child = true;
        }
        if(nodes[i]!=NULL){
            q.push(n);
        }
    }
}

void printTree(TreeNode * root, int indent){
    if(root!=NULL){
        printTree(root->right, indent+4);
        std::cout <<setw(indent)<< root->val <<std::endl;
        printTree(root->left, indent+4);
    }
}
