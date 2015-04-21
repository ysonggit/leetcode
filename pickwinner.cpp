#include <gtest/gtest.h>
#include <list>
#include "utils.h"
using namespace std;
/*
  given n people, with id [1,2,3.. n] and a number k
  for example, n = 3 k = 5
  [1 2 3 ]
  each person counts a number one-by-one
   1 2 3
   4 5
   the 2 counts 5 so it is out
   [1 3]
      from the removed person, the next one keep on counting from start
      1
   2  3
   4  5
     so 3 is out
   finally only 1 in, so 1 is the winner

   source : Bloomberg
 */
/*
int pickWinner(int n, int k){
    if(n==0) return -1;
    vector<int> ids;
    for(int i=1; i<=n; i++){
        ids.push_back(i);
    }
    while(ids.size()>1){
        int offset = k%(ids.size())-1;
        if(offset<0){
            offset = ids.size()-1;
        }
        ids.erase(ids.begin()+offset);
        if(offset<ids.size()) rotate(ids.begin(), ids.begin()+offset, ids.end());
    }
    return ids.front();
}

int pickWinner(int n, int k){
    if(n==0) return -1;
    list<int> ids;
    for(int i=1; i<=n; i++){
        ids.push_back(i);
    }
    int start_pos = 0;
    auto to_remove = ids.begin();
    while(ids.size()>1){
        int offset = k % (ids.size())-1; //mistake : k not n!
        if(offset < 0){
            offset = ids.size()-1;
        }
        advance(to_remove, (start_pos+offset)%ids.size()); 
        start_pos = distance(ids.begin(), to_remove);
        //cout<<"start pos now is "<<start_pos<<endl;
        ids.erase(to_remove);
        to_remove = ids.begin(); // mistake : forgot to reset
    }
    return *ids.begin();
    }*/

int pickWinner(int n, int k){
    if(n==0) return -1;
    ListNode * head = new ListNode(1);
    ListNode * cur = head;
    for(int i=2; i<=n; i++){
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    ListNode * pre = cur;
    cur->next = head;
    int rest = n;
    while(rest>1){
        int steps = k%(rest);
        ListNode * to_leave = head;
        for(int i=1; i<k; i++){
            pre = pre->next;
            to_leave = to_leave->next;
        }
        pre->next = to_leave->next;
        head = pre->next;
        rest--;
        delete to_leave;
        to_leave = NULL;
    }
    return head->val;
}

TEST(Winner, I){
    int n = 3;
    int k= 5;
    int res= 1;
    ASSERT_EQ(res, pickWinner(n, k));
}

TEST(Winner, II){
    int n = 8;
    int k= 2;
    int res= 1;
    ASSERT_EQ(res, pickWinner(n, k));
}


TEST(Winner, III){
    int n = 8;
    int k= 1;
    int res= 8;
    ASSERT_EQ(res, pickWinner(n, k));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
