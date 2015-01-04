#include "utils.h"

using namespace std;

/*
  idea: for each node,
        1. new a copy in a hashmap in which key is the node label, value is the node copy
        2. find the copied node in hashmap via its label,
        then copy random pointer to the value's random pointer
 */

RandomListNode * copyRandomList(RandomListNode * head){
    if(head == nullptr) return head;
    RandomListNode * cur = head;
    unordered_map<int, RandomListNode*> copied;
    while(cur != NULL){
        if(copied.find(cur->label) == copied.end()){
            copied[cur->label] = new RandomListNode(cur->label);
        }
        // 1. copy cur node's label and next pointer in map
        if(cur->next != NULL){
            int next_label = cur->next->label;
            if(copied.find(next_label) == copied.end()){
                copied[next_label] = new RandomListNode(next_label);
            }
            copied[cur->label]->next = copied[next_label];
        }
        // 2. copy cur node's random pointer in map
        if(cur->random != NULL){
            int rand_label = cur->random->label;
            if(copied.find(rand_label) == copied.end()) {
                copied[rand_label] = new RandomListNode(rand_label);
            }
            copied[cur->label]->random = copied[rand_label];
        }
        cur = cur->next;
    }
    return copied[head->label];
}

int main(int argc, char *argv[])
{
    RandomListNode * n1 = new RandomListNode(1);
    RandomListNode * n2 = new RandomListNode(2);
    RandomListNode * n3 = new RandomListNode(3);
    RandomListNode * n4 = new RandomListNode(4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->random = n1;
    n2->random = n4;
    printRandomList(n1);
    cout<<"----------------------\n";
    RandomListNode * m = copyRandomList(n1);
    printRandomList(m);
    return 0;
}


