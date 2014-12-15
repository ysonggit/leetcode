#include "utils.h"

using namespace std;
/*
  1<= m <= m <= list_length
  1. find the m^th node and n^th node
   ...-> pre -> m -> ... -> n -> post
  2. reverse from m to n^th node:
  3. join 3 seperate lists
      
 */

// return reversed head
ListNode * reverseNodes(ListNode * cur){
    ListNode * pre = NULL;
    ListNode * nex_cp;
    while(cur!= NULL){
        nex_cp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex_cp;
    }
    ListNode * rev_head = pre;
    return rev_head;
}

ListNode *reverseBetween(ListNode *head, int m, int n) {
    if(head==NULL || head->next == NULL ) return head;
    ListNode * fakehead = new ListNode(-1);
    fakehead->next = head;
    ListNode * pre = fakehead;
    ListNode * cur = head;
    // 1. find m node
    for(int i=1; i<m; i++){
        pre= pre->next;
        cur= cur->next;
    }
    pre->next = NULL;
    ListNode * node_m = cur;
    // 2. reverse till n^th node
    int times = n-m; // need n-m reverses
    for(int j=0; j<n-m; j++){
        cur = cur->next;
    }
    ListNode* post = cur->next; 
    cur->next = NULL;    
    ListNode * rev = reverseNodes(node_m);
    // 3. re-join three parts
    pre->next = rev;
    node_m->next = post;
    return fakehead->next;
}


int main(int argc, char *argv[]){
    vector<ListNode*> nodes1;
    int vals1[5] = {1,2,3,4,5};
    listInitializer(nodes1, vals1);
    printList(nodes1[0]);
    ListNode * n1 = reverseBetween(nodes1[0], 2, 4);
    printList(n1);
    return 0;
}

