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
#include <cstring> //strtok
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

template<typename T, int N>
int getArrayLength(T (&A)[N]){
    return sizeof(A)/sizeof(*A); 
}

template<typename T, int N>
void listInitializer(std::vector<ListNode * > & nodes, T (&vals)[N]){
    for(int i=0; i<N; i++){
        nodes.push_back(new ListNode(vals[i]));
    }
    for(int i=0; i<nodes.size()-1; i++){
        nodes[i]->next = nodes[i+1];
    }
}

void printList(ListNode * head){
    ListNode * cur = head;
    while(cur!=NULL){
        std::cout<<cur->val<<" -> ";
        cur = cur->next;
    }
    std::cout<<"NULL"<<std::endl;
}
