#include <gtest/gtest.h>
#include "utils.h"
using namespace std;

ListNode * partition(ListNode* head, int x){
    if(head==NULL) return NULL;
    ListNode * leftdummy = new ListNode(-1);
    ListNode * rightdummy = new ListNode(0);
    ListNode * left = leftdummy;
    ListNode * right = rightdummy;
    while(head != NULL){
        if(head->val < x){
            left->next = head;
            left = left->next;
        }else{
            right->next = head;
            right = right->next;
        }
        head = head->next;
    }
    right->next = NULL;
    left->next = rightdummy->next;
    return leftdummy->next;
}

TEST(Partition, I){
    int vals[] = {1,4,3,2,5,2};
    vector<ListNode*> nodes;
    listInitializer(nodes, vals);
    printList(nodes[0]);
    printList(partition(nodes[0], 3));
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


