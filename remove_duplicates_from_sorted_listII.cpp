#include "utils.h"

using namespace std;

/*
  pre -> cur ->
  
 */
void deleteNode(ListNode * to_be_deleted){
    delete to_be_deleted;
    to_be_deleted = NULL; // avoid danling pointers
}

ListNode *deleteDuplicates(ListNode *head) {
    if(head == NULL || head->next == NULL) return head;
    ListNode * fakehead = new ListNode(-1);
    fakehead->next = head;
    ListNode * pre = fakehead;
    ListNode * cur = head;
    while(cur != NULL){
        bool is_duplicate = false;
        while(cur->next != NULL && cur->val == cur->next->val){
            // cur has duplicates
            ListNode * to_be_deleted = cur;
            is_duplicate = true; // pre-next needs to be deleted after this while loop
            cur = to_be_deleted->next;
            deleteNode(to_be_deleted);
        }
        if(is_duplicate){
            ListNode * to_be_deleted = cur;
            cur = to_be_deleted->next;
            deleteNode(to_be_deleted);
        }
        pre->next = cur;
        if(!is_duplicate){
            cur = cur->next;
            pre = pre->next;
        }
    }
    return fakehead->next;
}

int  main(){
    vector<ListNode* > nodes;
    int vals[7] = {1,1,1,1,1,2,3};
    listInitializer(nodes, vals);
    printList(nodes[0]);
    ListNode * n = deleteDuplicates(nodes[0]);
    printList(n);

    vector<ListNode* > nodes2;
    int vals2[7] = {2,3,3,4,4,4,5};
    listInitializer(nodes2, vals2);
    printList(nodes2[0]);
    ListNode * n2 = deleteDuplicates(nodes2[0]);
    printList(n2);
    return 0;
}
