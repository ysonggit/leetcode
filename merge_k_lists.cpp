#include "utils.h"

using namespace std;

/*

  idea : divide and conquer
         every time merge two lists
         O(nklogk) time O(logk)

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

*/
//  non-recursive version merge two lists, O(1) space
//  take less time to execute
/*ListNode * merge2Lists(ListNode* l1, ListNode* l2){
    if(l1==nullptr && l2==nullptr) return nullptr;
    ListNode * fakehead = new ListNode(-1);
    ListNode * cur = fakehead;
    ListNode * h1 = l1;
    ListNode * h2 = l2;
    while(h1!= nullptr && h2 != nullptr){
        if(h1->val < h2->val){
            cur->next = h1;
            h1 = h1->next;
        }else{
            cur->next = h2;
            h2 = h2->next;
        }
        cur = cur->next;
    }
    if(h1!=nullptr) cur->next = h1;
    if(h2!=nullptr) cur->next = h2;
    return fakehead->next;
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
} */
class Comparator{
    public: 
        bool operator() (ListNode * a, ListNode *b){
            return a->val > b->val;
        }    
    };
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int k = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, Comparator> minheap;
        for(int i=0; i<k; i++){
            if(lists[i] != NULL){ 
                minheap.push(lists[i]);
                lists[i] = lists[i]->next;
            }
        }
        ListNode * dummy = new ListNode(-1);
        ListNode * cur = dummy;
        ListNode * to_insert = NULL;
        while(!minheap.empty()){
            cur ->next = minheap.top();
            to_insert = minheap.top()->next;
            minheap.pop();
            cur = cur->next;
            if(to_insert == NULL) continue;
            minheap.push(to_insert);
        }
        return dummy->next;
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
