#include "utils.h"
#include <gtest/gtest.h>

using namespace std;

bool isSameTree(TreeNode * p, TreeNode *q){
    if(p==nullptr && q==nullptr) return true;
    if(p==nullptr || q==nullptr) return false;
    return (p->val==q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

TEST(SameTree, I){
    TreeNode *p=nullptr;
    TreeNode *q=nullptr;
    ASSERT_EQ(true, isSameTree(p,q));
}

TEST(SameTree, II){
    string vals = "{4,2,5,1,3,#,6}";
    vector<TreeNode*> p, q;
    treeInitializer(p, vals);
    treeInitializer(q, vals);
    ASSERT_EQ(true, isSameTree(p[0],q[0]));
}

TEST(SameTree, III){
    string vals = "{4,2,5,1,3,#,6}";
    vector<TreeNode*> p, q;
    treeInitializer(p, vals);
    string vals1 = "{4,2,5,3,1,#,6}";
    treeInitializer(q, vals1);
    ASSERT_EQ(false, isSameTree(p[0],q[0]));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

