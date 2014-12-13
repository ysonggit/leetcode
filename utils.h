#include <utility> //pair
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>  // inserting takes O(logN)
#include <unordered_map> // constant time operation O(1)
#include <string>
#include <sstream>
#include <climits>

template <typename T>
void printVector(std::vector<T> v){
   for(T i : v){
      std::cout<<i<<" ";
   }
   std::cout<<std::endl;
}

template <typename T>
void print2DVector(std::vector<std::vector<T> > vv){
     for(std::vector<T> v: vv){
	  printVector(v);
     }
}


struct TreeNode {
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     int val;
     TreeNode *left;
     TreeNode *right;
};


struct ListNode {
ListNode(int x) : val(x), next(NULL) {}
     int val;
     ListNode *next;
};

void printList(ListNode * head){
    ListNode * cur = head;
    while(cur!=NULL){
        std::cout<<cur->val<<" -> ";
        cur = cur->next;
    }
    std::cout<<"NULL"<<std::endl;
}
