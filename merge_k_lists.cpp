#include "utils.h"

using namespace std;

/*
  idea : divide and conquer
         every time merge two lists
         O(nklogk) time O(logk)
 */

ListNode * merge2Lists(ListNode * l1, ListNode * l2){
    if(l1==nullptr && l2==nullptr) return nullptr;
    if(l1==nullptr) return l2;
    if(l2==nullptr) return l1;
    ListNode * mergehead = nullptr;
    if(l1->val<l2->val){
        mergehead = l1;
        mergehead->next = merge2Lists(l1->next, l2);
    }else{
        mergehead = l2;
        mergehead->next = merge2Lists(l1, l2->next);
    }
    return mergehead;
}

ListNode * divideConquer(vector<ListNode*> & lists, int left, int right){
    if(left < right ){
        int mid =(left + right)/2;
        ListNode * left_list = divideConquer(lists, left, mid);
        ListNode * right_list = divideConquer(lists, mid+1, right);
        return merge2Lists(left_list, right_list);
    }
    return lists[left];
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
    if(lists.size()==0) return nullptr;
    return divideConquer(lists, 0, lists.size()-1);
}

int main(int argc, char *argv[]){
    vector<ListNode*> lists;
    vector<ListNode*> l1, l2, l3;
    int A[6] = {1,2,3,4,5,8};
    int B[6] = {3,5,6,7,10,21};
    int C[7] = {2,9,11,13,15,16,19};
    listInitializer(l1, A);
    listInitializer(l2, B);
    listInitializer(l3, C);
    lists.push_back(l1[0]);
    lists.push_back(l2[0]);
    lists.push_back(l3[0]);
    ListNode * n = mergeKLists(lists);
    printList(n);
    return 0;
}
