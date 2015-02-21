#include "utils.h"
#include <gtest/gtest.h>

using namespace std;

/*
  similar to add binary
  deal with carry out
 */
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if(!l1 && !l2) return NULL;
    if(l1==NULL) return l2;
    if(l2==NULL) return l2;
    ListNode * fakehead = new ListNode(-1);
    ListNode * prev = fakehead; // important
    int carry = 0;
    for(; l1 != NULL || l2 != NULL;
        l1 = (!l1) ? NULL : l1->next, l2 = (!l2) ? NULL : l2->next){
        int a = (!l1) ? 0 : l1->val;
        int b = (!l2) ? 0 : l2->val;
        int c = (a + b + carry ) %10;
        carry = (a + b + carry ) /10;
        //cur  = new ListNode(c); //  won't work since created node is local variable
        prev->next = new ListNode(c); // modifies the list by reference
        prev = prev->next;
    }
    if (carry > 0){
        prev -> next =  new ListNode(carry);
    }
    return fakehead->next;
}

TEST(Add, I){
    vector<ListNode*> nodes1;
    vector<ListNode*> nodes2;
    int val1[]= {5};
    int val2[] = {5,1,1};
    listInitializer(nodes1, val1);
    listInitializer(nodes2, val2);
    printList(nodes1[0]);
    printList(nodes2[0]);
    ListNode * l = addTwoNumbers(nodes1[0], nodes2[0]);
    printList(l);
}

TEST(Add, II){
    printList(addTwoNumbers(NULL, NULL));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



