#include <gtest/gtest.h>
#include "utils.h"
using namespace std;

/*
  idea: two pointers 
  tip: dummy head      
  corner case:
  empty list
  cyclic list ? assume no cycle here
  n = 1  remove tail
  n = list length
         remove head
  one node list , n = 1
  dummy -> head -> nil

  dummy->..slow -> (slownext) ->.. fast -> (nil)

*/
ListNode *removeNthFromEnd(ListNode *head, int n) {
    if(!head || n<=0 ) return head;
    ListNode * dummy = new ListNode (-1);
    dummy->next = head;
    ListNode * fast = dummy;
    ListNode * slow = dummy;
    while(n--){
        fast = fast->next;
    }
    while(fast->next){
        fast = fast->next;
        slow = slow->next;
    }
    // slow->next is the node to be removed
    // slow->next is guaranteed non-nil
    ListNode * node_to_rm = slow->next;
    slow->next = node_to_rm->next;
    delete node_to_rm;
    node_to_rm = nullptr;
    return dummy->next;
}

TEST(RemoveNth, I){
    vector<ListNode*> nodes;
    int vals [] = {1,2,3,4,5};
    listInitializer(nodes, vals);
    printList(nodes[0]);
    printList(removeNthFromEnd(nodes[0], 2));
}

TEST(RemoveNth, II){
    vector<ListNode*> nodes;
    int vals [] = {1};
    listInitializer(nodes, vals);
    printList(nodes[0]);
    printList(removeNthFromEnd(nodes[0], 1));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}