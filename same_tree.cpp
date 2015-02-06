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

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

