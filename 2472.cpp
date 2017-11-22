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
  int from, to;
  double cost;
  edge(int from, int to, double cost) : from(from), to(to), cost(cost) {}
  bool operator<(const edge &r) const{ return cost < r.cost; }
  bool operator>(const edge &r) const{ return cost > r.cost; }
};

vector<vector<edge> > g;

void add_edge(int from, int to, double cost){
  g[from].push_back(edge(from, to, cost));
  g[to].push_back(edge(to, from, cost));
}

int prev_node[100100];
double dist[100100];
double dijkstra(vector<vector<edge> > g, int s, int t){
  int V = g.size();
  priority_queue<edge, vector<edge>, greater<edge> > Q;
  Q.push(edge(-2, s, 0));
  fill(dist, dist + 100100, 1e100);
  fill(prev_node, prev_node + 100100, -1);
  
  dist[s] = 0;
  while(!Q.empty()){
    edge e = Q.top(); Q.pop();
    if(prev_node[e.to] != -1) continue;

    prev_node[e.to] = e.from;
    for(int i = 0; i < g[e.to].size(); i++){
      edge f = g[e.to][i];
      if(dist[f.to] > dist[e.to] + f.cost){
	dist[f.to] = dist[e.to] + f.cost;
	Q.push(edge(f.from, f.to, f.cost + dist[e.to]));
      }
    }
  }  
  return dist[t];
}

int main(int argc, char **argv){
  int V, E;
  while(scanf("%d", &V), V){
    scanf("%d", &E);
    g.clear();
    g.resize(V);
    for(int i = 0; i < E; i++){
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      add_edge(a - 1, b - 1, -log(c / 100.0));
    }
    double d = -dijkstra(g, 0, V - 1);
    printf("%.6f percent\n", 100 * exp(d));
  }
}
