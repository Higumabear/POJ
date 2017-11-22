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
#include <cstring>
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
bool camp[610];
int prev_node[100100];
int dist[100100];
int dijkstra(vector<vector<edge> > g, int s, int t, bool flag){
  int V = g.size();
  priority_queue<edge, vector<edge>, greater<edge> > Q;
  Q.push(edge(-2, s, 0));
  fill(dist, dist + 100100, INF);
  fill(prev_node, prev_node + 100100, -1);
  
  dist[s] = 0;
  while(!Q.empty()){
    edge e = Q.top(); Q.pop();
    if(prev_node[e.to] != -1) continue;
    //if(camp[e.to] != flag) continue;

    prev_node[e.to] = e.from;
    for(int i = 0; i < g[e.to].size(); i++){
      edge f = g[e.to][i];
      if(camp[f.to] == flag && dist[f.to] > dist[e.to] + f.cost){
	dist[f.to] = dist[e.to] + f.cost;
	Q.push(edge(f.from, f.to, f.cost + dist[e.to]));
      }
    }
  }  
  return dist[t];
}

int ma[610][610];

int main(int argc, char **argv){
  int V, E;
  while(scanf("%d", &V), V){
    scanf("%d", &E);
    memset(ma, -1, sizeof(ma));

    g.clear();
    g.resize(V);
    for(int i = 0; i < E; i++){
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      add_edge(a - 1, b - 1, c);
      ma[a - 1][b - 1] = ma[b - 1][a - 1] = c;
    }
  
    for(int i = 0; i < V; i++){
      int x;
      scanf("%d", &x);
      if(x == 1) camp[i] = true;
      else camp[i] = false;
    }
    
    dijkstra(g, 0, 1, true);
    vector<int> d1(dist, dist + V);
    dijkstra(g, 1, 0, false);
    vector<int> d2(dist, dist + V);

    int ans = INF;
    for(int i = 0; i < V; i++){
      for(int j = 0; j < V; j++){
	if(i == j) continue;
	if(camp[i] != camp[j] && 
	   d1[i] != INF && d2[j] != INF &&
	   ma[i][j] != -1)
	  ans = min(ans, d1[i] + ma[i][j] + d2[j]);
      }
    }
    if(ans == INF)
      printf("-1\n");
    else
      printf("%d\n", ans);
  }
}
