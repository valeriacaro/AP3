/* Given a connected, undirected graph, a spanning tree of that graph is a
subgraph which is a tree and connects all the vertices together. On a weighted
graph, the weight of a spanning tree is the sum of the weights of its edges. A
minimum spanning tree is a spanning tree with weight less than or equal to the
weight of every other spanning tree.

Input

Input consists of different weighted, connected, undirected graphs. For each
graph, the following integers are given: First, n ≥ 1 represents the number of
vertices on the graph. Then, m represents the number of edges on the graph.
Finally, a set of m weighted edges u,v,w is given by specifying its two end
points u and v and its weight w ≥ 1. Vertices are numbered starting from 1.
There are no edges connecting a vertex to itself, but there may be more than
two edges connecting the same pair of vertices. Every given graph is connected.
All weights are strictly positive integers.

Output

For every graph in the input, write the weight of its minimum spanning tree. */

// INCLUDES
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ESTRUCTURES
using Node = int;
using Weight = int;

struct Arc{
  Node node;
  Weight weight;
};

bool operator< (const Arc& a, const Arc& b)
{
    return a.weight > b.weight;
}

using LlistaAdjacencies = vector<Arc>;
using Graph = vector<LlistaAdjacencies>;


// FUNCIONS I ACCIONS
bool read_graph(Graph& graph){
  int n, m;
  if (not (cin >> n >> m)) return false;
  graph = Graph(n+1);
  for (int i = 0; i < m; ++i){
    Node u, v;
    Weight w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }
  return true;
}

Weight minimum_spanning_tree_cost(const Graph& graph){
  int mst = 0;
  int V = graph.size() - 1;
  vector<bool> visited(V, false);
  visited[1] = true;
  int i = 1;

  priority_queue<Arc> pq;
  for(Arc neighb : graph[1]){
      pq.push({neighb.node, neighb.weight});
  }

  while(i < V){
    Arc a = pq.top();
    pq.pop();
    if(not visited[a.node]){
      visited[a.node] = true;
      mst += a.weight;
      ++i;
    }
    for(Arc neighb : graph[a.node]){
      if(not (visited[neighb.node])){
        pq.push({neighb.node, neighb.weight});
      }
    }
  }
  return mst;
}

// COS PRINCIPAL
int main(){
  Graph graph;
  while(read_graph(graph)){
    cout << minimum_spanning_tree_cost(graph) << endl;
  }
}
