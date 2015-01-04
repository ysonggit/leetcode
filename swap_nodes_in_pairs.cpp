#include "utils.h"
using namespace std;

/*
  for every two nodes, swap pairs

ListNode *swapPairs(ListNode *head) {
    // tip : add a dummy head
    ListNode * fakehead = new ListNode(-1);
    fakehead->next  = head;
    ListNode * cur = head;
    while(cur != NULL && cur->next != NULL){
        swap(cur->val, cur->next->val);
        cur= cur->next->next;
    }
    return fakehead->next;
    }*/

// pre -> cur -> curnex -> curnex.next
// pre -> curnex -> cur -> curnex.next
void swapNodes(ListNode * pre, ListNode * cur, ListNode * curnex){
    cur->next = curnex->next;
    curnex->next = cur;
    pre->next = curnex;
}

ListNode *swapPairs(ListNode *head) {
    // tip : add a dummy head
    ListNode * fakehead = new ListNode(-1);
    fakehead->next  = head;
    ListNode * cur = head;
    ListNode * pre = fakehead;
    while(pre != NULL && cur != NULL && cur->next != NULL){
        // save copy of cur->next->next
        ListNode * nexnex = cur->next->next;
        swapNodes(pre, cur, cur->next);
        pre = cur;
        cur= nexnex;
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


