#include <gtest/gtest.h>
#include "utils.h"
using namespace std;
// idea : two pointers
bool hasCycle(ListNode * head){
    ListNode * fast = head;
    ListNode * slow = head;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast) return true;
    }
    return false;
}

TEST(Cycle, I){
    int vals[] = {1,2,3,4,5,6};
    vector<ListNode*> nodes;
    listInitializer(nodes, vals);
    int res = false;
    ASSERT_EQ(res, hasCycle(nodes[0]));
}

TEST(Cycle, II){
    int vals[] = {1,2,3,4,5,6};
    vector<ListNode*> nodes;
    listInitializer(nodes, vals);
    nodes.back()->next = nodes.front();
    int res = true;
    ASSERT_EQ(res, hasCycle(nodes[0]));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


