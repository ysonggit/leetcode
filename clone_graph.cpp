#include "utils.h"
using namespace std;

/*
  seems the graph is given connected
  DFS traverse the graph
  maintains a set of graph nodes
 */
void dfs(map<int, UndirectedGraphNode*> & cloned, UndirectedGraphNode * node){
    cloned[node->label] = new UndirectedGraphNode(node->label);
    for(int i=0; i< node->neighbors.size(); i++){
        UndirectedGraphNode * adj = node->neighbors[i];
        if(cloned.find(adj->label)==cloned.end()){
            cloned[adj->label] = new UndirectedGraphNode(adj->label);
            dfs(cloned, adj);
        }
        cloned[node->label]->neighbors.push_back(cloned[adj->label]);
    }
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if(node==nullptr) return node;
    map<int, UndirectedGraphNode*> cloned;
    dfs(cloned, node);
    return cloned.begin()->second;
}

int main(int argc, char *argv[])
{
    string vals("{0,1,2#1,2#2,2}");
    map<int, UndirectedGraphNode*> graph_nodes = graphInitializer(vals);
    printGraph(graph_nodes[0]);
    cout<<"-------------clone---------------\n";
    UndirectedGraphNode * clone = cloneGraph(graph_nodes[0]);
    printGraph(clone);
    return 0;
}

