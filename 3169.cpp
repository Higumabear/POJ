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
const int INF = (1 << 30) - 1;

struct edge{
  int from, to, cost;
  edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
};

vector<vector<edge> > g;

void add_edge(int from, int to, int cost){
  g[from].push_back(edge(from, to, cost));
  //g[to].push_back(edge(to, from, cost));
}

int dist[1010];
int bellman_ford(const vector<vector<edge> > &g, int s, int t){
  int V = g.size();
  fill(dist, dist + 1010, INF);
  
  dist[s] = 0;
  for(int i = 0; i < V; i++){
    bool update = false;
    for(int j = 0; j < V; j++){
      for(int k = 0; k < g[j].size(); k++){
	edge e = g[j][k];
	if(dist[e.from] != INF && dist[e.to] > dist[e.from] + e.cost){
	  dist[e.to] = dist[e.from] + e.cost;
	  update = true;
	}
      }
    }
    if(update && i == V - 1) return -INF; 
  }
  return dist[t];
}

int main(int argc, char **argv){
  int N, ML, MD;
  scanf("%d %d %d", &N, &ML, &MD);

  int a, b, c;
  g.resize(N);
  for(int i = 0; i < ML; i++){
    scanf("%d %d %d", &a, &b, &c);
    add_edge(a - 1, b - 1, c);
  }
  for(int i = 0; i < MD; i++){
    scanf("%d %d %d", &a, &b, &c);
    add_edge(b - 1, a - 1, -c);
  }
  for(int i = 1; i < N; i++)
    add_edge(i, i - 1, 0);

  int v = bellman_ford(g, 0, N - 1);
  //printf("ans : %d\n", v);
  if(v == -INF) printf("-1\n");
  else{
    if(v == INF) printf("-2\n");
    else printf("%d\n", v);
  }
}
