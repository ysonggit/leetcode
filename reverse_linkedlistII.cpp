#include "utils.h"

using namespace std;
/*
  1<= m <= m <= list_length
  1. find the m^th node and n^th node
   ...-> pre -> m -> ... -> n -> post
  2. reverse from m to n^th node:
  3. join 3 seperate lists
      
 */
 
 
ListNode *reverseBetween(ListNode *head, int m, int n) {
  if(head==NULL) return NULL;
  if(m==n) return head;
  ListNode * dummy = new ListNode(-1);
  dummy->next = head;
  ListNode * cur = dummy->next;
  ListNode * pre = dummy;
  for(int i=1; i<m; i++){
    pre = pre->next;
    cur = cur->next;
  }
  pre->next = NULL;
  ListNode * rev_start = cur;
  ListNode * rev_pre = NULL;
  ListNode * rev_end = cur;
  int k = n-m+1;// watch out!
  while(k>0){
      ListNode * rev_nex = rev_start->next;
      rev_start->next = rev_pre;
      rev_pre = rev_start;
      rev_start =rev_nex;
      k--;
  }
  pre->next = rev_pre;
  rev_end->next = rev_start;
  return dummy->next;
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

