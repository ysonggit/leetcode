#include "utils.h"

using namespace std;

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if(!l1 && !l2) return nullptr;
    if(l1 == nullptr ) return l2;
    if(l2 == nullptr ) return l1;
    ListNode * fakehead = new ListNode(-1);
    ListNode * cur = fakehead;
    while(l1!= nullptr && l2 != nullptr){
        if(l1->val < l2->val){
            cur->next = l1;
            l1 = l1->next;
        }else{
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    // l1 or l2 may be still not NULL
    // clean up
    cur->next = (l1==nullptr)? l2 : l1;
    return fakehead->next;
}

int main(int argc, char *argv[]){
    vector<ListNode*> l1;
    int A[] = {1,3,5,7,9};
    vector<ListNode*> l2;
    int B[] = {2,4,6,8,8};
    listInitializer(l1, A);
    listInitializer(l2, B);
    ListNode * n = mergeTwoLists(l1[0], l2[0]);
    printList(n);
    return 0;
}


