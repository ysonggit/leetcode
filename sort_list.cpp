#include <gtest/gtest.h>
#include "utils.h"

using namespace std;
/*
  solution from  anniekim.pku[at]gmail.com
  idea : merge sort list
  // assume the list does not contain any loop
  key: dummy head
       break list by half(two pointers)
*/
int getLength(ListNode * head){
    int len = 0;
    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}

ListNode * inplaceMerge(ListNode * left, ListNode * right){
    ListNode * dummy = new ListNode(-1);
    ListNode * cur = dummy; // tip
    while(left && right){
        // using shared_ptr here is not a good idea
        ListNode** min_node_ptr =  (left->val < right->val) ? &left : &right;
        cur->next = *min_node_ptr;
        cur= cur->next;
        (*min_node_ptr) = (*min_node_ptr)->next;
    }
    if(!left) cur->next = right;
    if(!right) cur->next = left;
    return dummy->next;
}
/*
  head: (6) -> (5) -> (4), N = 3
    |_ left = mergeSort(head, 1)
            head (5)->(4) , and return left as (6)->null
       |
       |_ right = mergeSort(head, 2)
           |_  left = mergeSort(head, 1)
                   head : (4), and return left as (5)->null
           |_  right = mergeSort(head, 1)
                   head : null, return right as (4)->null
           |_  inplaceMerge(left, right)  ==> right is returned as (4)->(5)
       |
       |_  inplaceMerge(left, right) ==> (4)->(5)->(6)
       
 */
ListNode * mergeSort(ListNode *& head, int N){// pass by reference of node ptr to modify original head ptr
    if(N==0) return head;
    if(N==1){
        // base case
        ListNode * half = head;
        head = head->next;
        half->next = NULL; // break list into single node
        return half;
    }
    ListNode * left = mergeSort(head, N/2);
    // half-> next, it is the start node of right half
    ListNode * right = mergeSort(head, N-N/2);
    return inplaceMerge(left, right);
}

ListNode * sortList(ListNode * head){
    int len = getLength(head);
    return mergeSort(head, len);
}


TEST(SortList, I){
    vector<ListNode*> nodes;
    int vals[] ={6,5,4,3,2};
    listInitializer(nodes, vals);
    ListNode * n = sortList(nodes[0]);
    printList(n);
}

TEST(SortList, II){
    vector<ListNode*> nodes;
    int vals[] ={6,5,1,4,3,2};
    listInitializer(nodes, vals);
    ListNode * n = sortList(nodes[0]);
    printList(n);
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



