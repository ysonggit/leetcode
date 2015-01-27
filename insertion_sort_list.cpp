#include "utils.h"

using namespace std;
/*
  insertion sort template for array:
  for i = 1 .. A.length-1
     j= i
     while(j>0 && A[j-1] > A[j]){
          swap(A[j-1], A[j])
          j--
     }
 */
void showNode(ListNode * node){
    if(node==NULL) {
        cout<<"NULL\n";
        return ;
    }
    cout<<node->val<<" -> ";
    if(node->next != NULL){
        cout<<node->next->val<<endl;
    }else{
        cout<<"NULL\n";
    }
}

void showAllNodes(vector<ListNode*> & nodes){
    cout<<"--------------------\n";
    for_each(nodes.begin(), nodes.end(), showNode);
}

ListNode *insertionSortList(ListNode *head) {
    if(head==nullptr || head->next == nullptr) return head;
    ListNode * fakehead = new ListNode(INT_MIN);
    fakehead->next = head;
    for(ListNode *cur = head->next, * pre = head; cur != nullptr; pre = cur, cur = cur->next){
        printList(fakehead->next);
        for(ListNode * iter = fakehead; iter->next != cur; iter = iter->next){
            if(iter->next->val > cur->val){
                // insert pre->next between cur and cur->next
                // iter -> pre -> cur -> cur->next  ...
                //               |
                // iter -> cur -> pre -> nex_cp .. 
                pre->next = cur->next; // iter->next->next = cur_next is wrong
                cur->next = iter->next; 
                iter->next = cur;
                cur = pre;
                break;
            }
        }
    }
    return fakehead->next;
}

int main(int argc, char *argv[]){
    int A[] = {7,-5,2,16,4};
    vector<ListNode *> nodes;
    listInitializer(nodes, A);
    ListNode * n = insertionSortList(nodes[0]);
    printList(n);
    return 0;
}


