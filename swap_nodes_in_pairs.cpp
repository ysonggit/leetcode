#include "utils.h"
using namespace std;

/*
  for every two nodes, swap pairs
  trick : swap values of nodes but not pointers
 */

void swapNodes(ListNode * n1, ListNode * n2){
    if(n1==NULL || n2 == NULL) return ;
    int v1 = n1->val;
    n1->val = n2->val;
    n2->val = v1;
}

ListNode *swapPairs(ListNode *head) {
    // tip : add a dummy head
    ListNode * fakehead = new ListNode(-1);
    fakehead->next  = head;
    ListNode * cur = head;
    while(cur != NULL && cur->next != NULL){
        swapNodes(cur, cur->next);
        cur= cur->next->next;
    }
    return fakehead->next;
}


int  main(int argc, char *argv[]){
    ListNode * n1 = new ListNode(1);
    ListNode * n2 = new ListNode(2);
    ListNode * n3 = new ListNode(3);
    ListNode * n4 = new ListNode(4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    ListNode * n = swapPairs(n1);
    printList(n);
    return 0;
}


