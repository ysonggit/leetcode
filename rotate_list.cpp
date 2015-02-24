#include <gtest/gtest.h>
#include "utils.h"

using namespace std;

/*
  idea:
  1 traverse the list to get the length
  2 traverse the second time , move pointer n-k%n times
  3 the next node will be the head, and the n-k%n th node is the tail
  // assume the list has no circle, otherwise, check circle first
 */

ListNode *rotateRight(ListNode *head, int k) {
    if(!head || k<=0) return head;
    //1 get list length
    int n=1;
    ListNode * cur = head;
    while(cur->next!= NULL){ // do not write cur != NULL
        cur=cur->next;
        n++;
    }
    //2. connect tail to the old head , move n-k%n steps ahead
    cur->next = head;  // make sure cur is not nullptr
    for(int i=0; i<n-k%n; i++){
        cur = cur->next;
    }
    //3. save a copy of cur->next, this is the new head
    ListNode * newhead = cur->next;
    //4. then set cur->next to tail, otherwise it is a circle
    cur->next = NULL;
    return newhead;
}

TEST(RotateList, I){
    vector<ListNode*> nodes;
    int vals[] ={1,2,3,4,5};
    int k = 2;
    listInitializer(nodes, vals);
    printList(nodes[0]);
    printList(rotateRight(nodes[0], k));
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



