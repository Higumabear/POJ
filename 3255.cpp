/*
  Dijkstra shortest path problem

  Complexity:
  O(m log n) 
  n : number of vertices
  m : number of edges 
  
  Verified:
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

typedef long long ll;
const int INF = (1 << 31) - 1;

struct edge{
  int from, to, cost;
  edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
  bool operator<(const edge &r) const{ return cost < r.cost; }
  bool operator>(const edge &r) const{ return cost > r.cost; }
};

vector<vector<edge> > g;

void add_edge(int from, int to, int cost){
  g[from].push_back(edge(from, to, cost));
  g[to].push_back(edge(to, from, cost));
}

//distに最短距離が入る。経路がない場合はINF。
//prev_nodeにそのノードの一つ前のノードが入る。
//idx == prev_node[idx] となったら始点
vector<int> dist[5001];
void dijkstra(vector<vector<edge> > g, int s, int t){
  int V = g.size();
  priority_queue<edge, vector<edge>, greater<edge> > Q;
  Q.push(edge(-2, s, 0));
  
  while(!Q.empty()){
    edge e = Q.top(); Q.pop();
    if(dist[e.to].size() >= 2) continue;
    dist[e.to].push_back(e.cost);
    for(int i = 0; i < g[e.to].size(); i++){
      edge f = g[e.to][i];
      Q.push(edge(f.from, f.to, f.cost + e.cost));
    }
  }  
  return;
}

int main(int argc, char **argv){
  int V, E;
  scanf("%d %d", &V, &E);

  g.resize(V);
  for(int i = 0; i < E; i++){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    add_edge(a - 1, b - 1, c);
  }
  dijkstra(g, 0, V - 1);
  printf("%d\n", dist[V - 1][1]);
}
