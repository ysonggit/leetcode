#include "utils.h"

using namespace std;

/*
  idea : for a binary search tree, inorder traversal gives a monotonically increasing sequence
  use a queue to store the inorder traversal sequence of the binary search tree
  (that is, this is a question related with inorder traversal)

  the input must be a valid binary search tree
 */

class BSTIterator {
private:
    queue<int> smallest;
public:
    BSTIterator(TreeNode *root) {
        stack<TreeNode*> parents;
        TreeNode * cur = root;
        while(!parents.empty() || cur != nullptr){
            if(cur != nullptr){
                parents.push(cur);
                cur = cur->left;
            }else{
                cur = parents.top();
                parents.pop();
                if(cur != nullptr) smallest.push(cur->val);
                cur = cur->right;
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !smallest.empty();
    }

    /** @return the next smallest number */
    int next() {
        int next_smallest = smallest.front();
        smallest.pop();
        return next_smallest;
    }
};


int main(int argc, char *argv[]){
    string vals = "{4,2,5,1,3,#,6}";
    vector<TreeNode*> nodes;
    treeInitializer(nodes, vals);
    BSTIterator i = BSTIterator(nodes[0]);
    while (i.hasNext()) cout << i.next() <<" "; 
    cout<<endl;
    return 0;
}
