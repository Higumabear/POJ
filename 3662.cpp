#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
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

int V, E, K;
vector<edge> g[1001];

void add_edge(int from, int to, int cost){
  g[from].push_back(edge(from, to, cost));
}

//distに最短距離が入る。経路がない場合はINF。
//prev_nodeにそのノードの一つ前のノードが入る。
//idx == prev_node[idx] となったら始点
int prev_node[1001];
int dist[1001];
int dijkstra(int s, int t){
  priority_queue<edge, vector<edge>, greater<edge> > Q;
  Q.push(edge(s, s, 0));
  fill(dist, dist + 1001, INF);
  fill(prev_node, prev_node + 1001, -1);
  
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

int a[10000], b[10000], c[10000];
int mat[1001][1001];

int main(int argc, char **argv){
  scanf("%d %d %d", &V, &E, &K);

  int ub = 0, lb = 1;
  for(int i = 0; i < E; i++){
    scanf("%d %d %d", a + i, b + i, c + i);
    mat[a[i] - 1][b[i] - 1] = mat[b[i] - 1][a[i] - 1] = c[i];
    ub = max(ub, c[i]);
  }

  int ans = INF;
  while(lb + 1 < ub){
    for(int i = 0; i < V; i++) g[i].clear();
    int mid = (ub + lb) / 2;
    for(int i = 0; i < E; i++){
      add_edge(a[i] - 1, b[i] - 1, c[i] >= mid ? 1 : 0);
      add_edge(b[i] - 1, a[i] - 1, c[i] >= mid ? 1 : 0);
    }
    
    
    //cout << lb << " : " << mid << " : " << ub << endl;
    int d = dijkstra(0, V - 1);
    if(d <= K){
      //cout << d << endl;
      //if(d == 0) ans = 0;
      int u = V - 1;
      int longest = 0;
      while(prev_node[u] != u){
	//cout << u << " -> " << prev_node[u] << endl;
	if(mat[prev_node[u]][u] < mid)
	  longest = max(longest, mat[prev_node[u]][u]);
	u = prev_node[u];
      }
      ans = min(ans, longest);
      ub = mid;
    }else{
      lb = mid;
    }
  }
  printf("%d\n", ans == INF ? -1 : ans);
}
