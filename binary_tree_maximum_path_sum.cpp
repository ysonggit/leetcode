#include "utils.h"
#include <list>
using namespace std;
/*
  For every node in given tree, math sum of paths can be obtained by 
  max(sum_left_subtree, sub_right_subtree)
  node + left_subpath  (subpath != subtree)
  node + right_subpath
  node + left_subpath + right_subpath

  subpath only contains node on either left or right side
 */


int main(int argc, char *argv[]){
    string vals = "{1,2,3,#,#,4,#,#,5}";
    vector<TreeNode*> nodes;
    treeInitializer(nodes, vals);
    printTree(nodes[0], 2);
    return 0;
}

