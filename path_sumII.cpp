
#include "utils.h"
#include "treenode.h"

using namespace std;

bool isLeaf(TreeNode * node){
    if(node->left == NULL && node->right == NULL){
        return true;
    }
    return false;
}

int getSum(vector<int> v){
    int sum = 0;
    for(int i: v){
        sum += i;
    }
    return sum;
}
// trick : parameter path should not be passed by reference
void dfs(vector<vector<int> > & allpaths, TreeNode * root, vector<int> path, int sum){
    path.push_back(root->val);

    if(isLeaf(root) && sum == getSum(path)){
        allpaths.push_back(path);
        return;
    }
    if(root->left != NULL){
        dfs(allpaths, root->left, path, sum);        
    }
    if(root->right != NULL){
        dfs(allpaths, root->right, path, sum);
    }
    path.pop_back();
}

    

vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<vector<int> > allpaths;
    if(root==NULL) return allpaths;
    vector<int> path;
    dfs(allpaths, root, path, sum);
    return allpaths;
}

int main(){
    int sum = 1;
    TreeNode * n1 = new TreeNode(0);
    TreeNode * n2 = new TreeNode(1);
    TreeNode * n3 = new TreeNode(1);
    // TreeNode * n4 = new TreeNode(11);
    // TreeNode * n5 = new TreeNode(13);
    // TreeNode * n6 = new TreeNode(4);
    // TreeNode * n7 = new TreeNode(7);
    // TreeNode * n8 = new TreeNode(2);
    // TreeNode * n9 = new TreeNode(5);
    // TreeNode * n10 = new TreeNode(1);
    n1->left = n2;
    n1->right = n3;
    //n2->left = n4;
    // n4->left = n7;
    // n4->right = n8;
    // n3->left = n5;
    // n3->right = n6;
    // n6->left = n9;
    // n6->right = n10;
    vector<vector<int> > allpaths;
    allpaths = pathSum(n1, sum);
    print2DVector(allpaths);
    return 0;
}
