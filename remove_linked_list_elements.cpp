#include <gtest/gtest.h>
#include "utils.h"
using namespace std;

ListNode* removeElements(ListNode* head, int val) {
    if(head==NULL) return NULL;
    ListNode*  dummy = new ListNode(-1);
    dummy->next = head;
    ListNode * cur = dummy;
    while(cur!=NULL && cur->next != NULL){ // mistake: cur->next != null is not enough
        while(cur->next->val == val){
            ListNode * to_del = cur->next;
            cur->next = cur->next->next;
            delete to_del;
            if(cur->next == NULL) break;
        }
        cur = cur->next;
    }
    return dummy->next;
}

TEST(RemoveListNode, I){
    int A[] = {1,2,3,6,6,6,6};
    vector<ListNode*> nodes;
    int val = 6;
    listInitializer(nodes, A);
    printList(nodes[0]);
    printList(removeElements(nodes[0], val));
}
TEST(RemoveListNode, II){
    int A[] = {1};
    vector<ListNode*> nodes;
    int val = 1;
    listInitializer(nodes, A);
    printList(nodes[0]);
    printList(removeElements(nodes[0], val));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}