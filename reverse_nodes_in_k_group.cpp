#include "utils.h"

using namespace std;
/*
  idea : for every k nodes, reverse and rejoin

  ... pre -> ( k nodes ) -> nex -> ...
              |
   ... pre -> (reversed) -> nex  ->

 */
// reverse sublists and then rejoin to the origin list
// reversed sublist will ends at NULL
ListNode * reverseKNodes(ListNode * cur, ListNode * end){
    ListNode * pre = NULL;
    ListNode * nex_cp = NULL;
    while(cur != end){
        nex_cp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex_cp;
    }
    return pre;
}

ListNode *reverseKGroup(ListNode *head, int k) {
    if(head==NULL || k<=1) return head;
    ListNode * fakehead = new ListNode(-1);
    fakehead->next = head;
    ListNode * pre = fakehead;
    ListNode * cur = pre->next;
    int i=0;
    ListNode * nex_backup = NULL;
    while(cur != NULL){
        i++;
        if(i%k==0){
            // reverse k nodes then move on
            // tricky: make a copy of next node to rejoin
            nex_backup = cur->next;
            //  cout<<"Next node backup : "<<nex_backup->val<<endl;
            pre->next = reverseKNodes(pre->next, cur->next);
            // printList(pre);
            // find the tail (non-nullptr) nodes of the list to connect with nex_backup
            ListNode * tail = pre->next;
            for(int j=0; j<k-1; j++) {
                tail = tail->next;
            }
            tail->next = nex_backup;
            pre = tail;
            cur = nex_backup; // don't forget to resume "cur" to the position it should be,
                              // otherwise, the variable "cur" will be reversed node
        }else{
            cur = cur->next;
        }
    }
    return fakehead->next;
}

int main(int argc, char *argv[]){
    int A[] = {1,2,3,4,5};
    vector<ListNode*> nodes;
    listInitializer(nodes, A);
    printList(nodes[0]);
    ListNode * n = reverseKGroup(nodes[0], 3);
    printList(n);
    return 0;
}


