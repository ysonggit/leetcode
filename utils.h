#include <utility> //pair
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <map>  // inserting takes O(logN)
#include <unordered_map> // constant time operation O(1)
#include <string>
#include <sstream>
#include <climits>
#include <cstring> //strtok
#include <iomanip>      //setw
#include <set>

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

///////////////////////////////////////////////////////////
//              Functions for Linked List               //
///////////////////////////////////////////////////////////
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

void printList(ListNode * head);

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

void printRandomList(RandomListNode * head);

///////////////////////////////////////////////////////////
//              Functions for Binary Tree                //
///////////////////////////////////////////////////////////
struct TreeNode {
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     int val;
     TreeNode *left;
     TreeNode *right;
};

std::vector<std::string> split(const std::string &s, char delim);

void treeInitializer(std::vector<TreeNode *> & nodes, const std::string & vals);

void printTree(TreeNode * root, int indent);

/**********************************************
              Interval Definition
 *********************************************/

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

std::ostream & operator<<(std::ostream & lhs, const Interval & it);


///////////////////////////////////////////////////////////
//              Functions for Undirected Graph           //
///////////////////////////////////////////////////////////

struct UndirectedGraphNode {
    int label;
    std::vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

std::map<int, UndirectedGraphNode*> graphInitializer(const std::string & vals);

void printGraphNode(UndirectedGraphNode * node);

void printGraph(UndirectedGraphNode * node);




