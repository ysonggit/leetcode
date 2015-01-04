#include "utils.h"
using namespace std;

///////////////////////////////////////////////////////////
//              Functions for Linked List               //
///////////////////////////////////////////////////////////
void printList(ListNode * head){
    ListNode * cur = head;
    while(cur!=NULL){
        std::cout<<cur->val<<" -> ";
        cur = cur->next;
    }
    std::cout<<"NULL"<<std::endl;
}

void printRandomList(RandomListNode * head){
    RandomListNode * cur = head;
    // first traversal: print next
    while(cur!=NULL){
        std::cout<<"("<<cur->label<<")  -> ";
        cur = cur->next;
    }
    std::cout<<"NULL"<<std::endl;
    // second/third traversal: print  random
    cur = head;
    while(cur!=NULL){
        std::cout<<" | \t";
        cur = cur->next;
    }
    std::cout<<"\n";
    cur = head;
    while(cur!=NULL){
        if(cur->random != nullptr){
            std::cout<<"("<<cur->random->label<<")\t";
        }else{
            std::cout<<"( )\t";
        }
        cur = cur->next;
    }
    std::cout<<"\n";
}

///////////////////////////////////////////////////////////
//              Functions for Binary Tree                //
///////////////////////////////////////////////////////////
std::vector<std::string> split(const std::string &s, char delim) {
    std::istringstream ss(s);
    std::string item;
    std::vector<std::string> tokens;
    while (std::getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}

// input string contains brackets "{}"
void treeInitializer(std::vector<TreeNode *> & nodes, const std::string & vals){
    //1. pass by left & right brackets {}
    std::size_t left_idx = vals.find("{");
    std::size_t right_idx = vals.find("}"); // indices of {}
    // truncate the original string by copying only values
    std::string values = vals.substr(left_idx+1, right_idx-left_idx-1);
    if(values.length()==0) return;
    std::vector<std::string> tokens = split(values, ',');
    for(int i=0; i<tokens.size(); i++){
        TreeNode * n = NULL;
        std::string str = tokens[i];
        if(str.find("#") == std::string::npos){
            int val = stoi(str);
            n  = new TreeNode(val);
        }
        nodes.push_back(n);
    }
    bool left_child = true;
    std::queue<TreeNode*> q;
    q.push(nodes[0]);
    TreeNode * cur = NULL;
    for(int i=1; i< nodes.size(); i++){
        TreeNode * n = nodes[i];
        if(left_child){
            cur = q.front();
            q.pop();
            left_child = false;
            cur->left = n;
        }else{
            cur->right = n;
            left_child = true;
        }
        if(nodes[i]!=NULL){
            q.push(n);
        }
    }
}

void printTree(TreeNode * root, int indent){
    if(root!=NULL){
        printTree(root->right, indent+4);
        std::cout <<setw(indent)<< root->val <<std::endl;
        printTree(root->left, indent+4);
    }
}

ostream & operator<<(ostream & lhs, const Interval & it){
    lhs << "[" << it.start << ", " << it.end << "]\n";
    return lhs;
}


/*
  the representation of an undirected graph is given as "{0,1,2#1,2#2,2}"
 */
std::map<int, UndirectedGraphNode*> graphInitializer(const std::string & vals){
    std::map<int, UndirectedGraphNode*> nodes; // key is the label
    //1. pass by left & right brackets {}
    std::size_t left_idx = vals.find("{");
    std::size_t right_idx = vals.find("}"); // indices of {}
    // truncate the original string by copying only values
    std::string values = vals.substr(left_idx+1, right_idx-left_idx-1);
    if(values.length()==0) return nodes;
    //2. split by #
    std::vector<std::string> segments = split(values, '#');
    //3. for each splitted segment, the first one is the node 
    //                              others are labels of its neighbors
    for(int i=0; i<segments.size(); i++){
        // 3.1 obtain all labels by removing comma's
        std::vector<std::string> labels = split(segments[i], ',');
        if(labels.empty()) continue; // jump to next iteration
        int host_label = std::stoi(labels[0]);
        if(nodes.find(host_label) == nodes.end()) {
            UndirectedGraphNode * host = new UndirectedGraphNode(host_label);
            nodes[host_label] = host;
        }
        for(int j=1; j<labels.size(); j++){
            int neighbor_label = std::stoi(labels[j]);
            if(nodes.find(neighbor_label) == nodes.end()){
                UndirectedGraphNode * neighbor = new UndirectedGraphNode(neighbor_label);
                nodes[neighbor_label] = neighbor;
            }
            nodes[host_label]->neighbors.push_back(nodes[neighbor_label]);
        }
    }
    return nodes;
}

void printGraphNode(UndirectedGraphNode * node){
    std::cout<<"("<<node->label<<")\n";
    for(UndirectedGraphNode * n : node->neighbors){
        std::cout<<" |\n";
        std::cout<<" -- ("<<n->label<<")\n";
    }
    std::cout<<std::endl;
}

// BFS traversal
void printGraph(UndirectedGraphNode * node){
    std::queue<UndirectedGraphNode *> q;
    std::set<UndirectedGraphNode*> visited;
    q.push(node);
    visited.insert(node);
    while(!q.empty()){
        UndirectedGraphNode * cur = q.front();
        printGraphNode(cur);
        q.pop();
        // get all adjacent neighbors of current node, if an adjacent is not visited
        // then mark it visited and enqueue
        for(UndirectedGraphNode * adj : cur->neighbors){
            if(visited.find(adj) == visited.end()){
                visited.insert(adj);
                q.push(adj);
            }
        }
    }
}