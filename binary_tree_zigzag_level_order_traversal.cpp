#include "utils.h"

using namespace std;
/*
  idea: modify original level-order traversal method
        maintains a variable level: 0 - H-1
        and two queues
        if level is odd : print from  right to left
        if level is even : print from  left to right
 */
vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<vector<int> > all_values;
    if(root == nullptr) return all_values;
    deque<TreeNode*> cur_level, next_level;
    cur_level.push_back(root);
    int level = 0;
    vector<int> cur_level_val;
    while(!cur_level.empty()){
        TreeNode * cur;
        cur = cur_level.front();
        cur_level.pop_front();
        cur_level_val.push_back(cur->val);
        if(cur->left != nullptr) next_level.push_back(cur->left);
        if(cur->right != nullptr) next_level.push_back(cur->right);
        if(cur_level.empty()){
            if (level & 1){
                // bitwise operation runs fast
                // level is odd
                // print from right to left
                reverse(cur_level_val.begin(), cur_level_val.end());
            }
            all_values.push_back(cur_level_val);
            cur_level_val.clear();
            cur_level.swap(next_level);
            level++;
        }
    }
    return all_values;
} 

int main(int argc, char *argv[])
{
    string vals = "{3,9,20,#,#,15,7}";
    vector<TreeNode*> nodes;
    treeInitializer(nodes, vals);
    printTree(nodes[0], 2);
    cout<<"-----------------------\n";
    vector<vector<int> > zigzag = zigzagLevelOrder(nodes[0]);
    print2DVector(zigzag);

    string vals1 = "{1,2,3,4,#,#,5}";
    vector<TreeNode*> nodes1;
    treeInitializer(nodes1, vals1);
    printTree(nodes1[0], 2);
    cout<<"-----------------------\n";
    vector<vector<int> > zigzag1 = zigzagLevelOrder(nodes1[0]);
    print2DVector(zigzag1);
    return 0;
}

