/* Write a program that, given a directed graph with positive costs at the arcs,
and two vertices x and y, computes the minimum cost to go from x to y.

Input

Input consists of several cases. Every case begins with the number of vertices n
and the number of arcs m. Follow m triples u, v, c, indicating that there is an
arc u → v of cost c, where u ≠ v and 1 ≤ c ≤ 1000. Finally, we have x and y.
Assume 1 ≤ n ≤ 104, 0 ≤ m ≤ 5n, and that for every pair of vertices u and v there
is at most one arc of the kind u → v. All numbers are integers. Vertices are
numbered from 0 to n−1.

Output

For every case, print the minimum cost to go from x to y, if this is possible.
If there is no path from x to y, state so. */

// INCLUDES
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// STRUCTURES AND DEFINITIONS
using Node = int;
using Weight = int;

const int Nil = -1;
const int Infinity = 1000000000;

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
Graph read_graph(int& n, int& m){
  Graph G(n);
  for (int i = 0; i < m; ++i){
    Node origin, final;
    Weight cost;
    cin >> origin >> final >> cost;
    Arc arc;
    arc.node = final;
    arc.weight = cost;
    G[origin].push_back(arc);
  }
  return G;
}

void Dijkstra(Graph& G, Node& origin, Node& final){
  int n = G.size();
  vector<Weight> dist(n, Infinity);
  vector<Node> prev(n, Nil);
  vector<bool> S(n, false);
  dist[origin] = 0;
  priority_queue<Arc> cua;
  cua.push({origin, dist[origin]});
  while (not cua.empty()){
    Node u = cua.top().node;
    cua.pop();
    if (not S[u]){
      S[u] = true;
      for (Arc arc : G[u]) {
        Node v = arc.node;
        Weight weight = arc.weight;
        if (dist[v] > dist[u] + weight) {
          dist[v] = dist[u] + weight;
          prev[v] = u;
          cua.push({v, dist[v]});
        }
      }
      if (u == final){
        cout << dist[u] << endl;
        return;
      }
    }
  }
  cout << "no path from " << origin << " to " << final << endl;
}

// COS PRINCIPAL
int main(){
  int n, m;
  while (cin >> n >> m){
    Graph G = read_graph(n, m);
    Node origin, final;
    cin >> origin >> final;
    Dijkstra(G, origin, final);
  }
}
