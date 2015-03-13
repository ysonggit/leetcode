#include <gtest/gtest.h>
#include "utils.h"
using namespace std;
/*
  idea :
  1. set two pointers :
  2. when fast and slow meet, reset slow to head
  3. move slow and fast at the same rate
  4. return the new collision node
*/
ListNode* detectCycle(ListNode * head){
    ListNode * fast = head;
    ListNode * slow = head;
    bool cyclic = false;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast) {
            cyclic = true;
            break;
        }
    }
    if(!cyclic) return nullptr;
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

TEST(Cycle, I){
    int vals[] = {1,2,3,4,5,6};
    vector<ListNode*> nodes;
    listInitializer(nodes, vals);
    ListNode * res  = nullptr;
    ASSERT_EQ(res, detectCycle(nodes[0]));
}

TEST(Cycle, II){
    int vals[] = {1,2,3,4,5,6};
    vector<ListNode*> nodes;
    listInitializer(nodes, vals);
    nodes.back()->next = nodes.front();
    ListNode * res = nodes[0];
    ASSERT_EQ(res, detectCycle(nodes[0]));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


