// Time-stamp: <Thu Mar 16 23:00:31 東京 (標準時) 2017>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 60
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define CNT(c,x) count(ALL(c),x)
#define dump(x)  cerr << #x << " = " << (x) << endl;
template<typename A, size_t N, typename T>
void FILL(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

using namespace std;

struct edge{
  int from, to, cost;
  edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
};


//distに最短距離が入る。経路がない場合はINF。負閉路を含む場合は-INF
//prev_nodeにそのノードの一つ前のノードが入る。
//idx == prev_node[idx] となったら始点
int prev_node[100100];
int dist[100100];
int bellman_ford(const vector<vector<edge> > &g, int s, int t){
  int V = g.size();
  fill(dist, dist + 100100, INF);
  fill(prev_node, prev_node + 100100, -1);
  
  dist[s] = 0;
  prev_node[s] = s;
  for(int i = 0; i < V; i++){
    bool update = false;
    for(int j = 0; j < V; j++){
      for(int k = 0; k < g[j].size(); k++){
	edge e = g[j][k];
	if(dist[e.from] != INF && dist[e.to] > dist[e.from] + e.cost){
	  dist[e.to] = dist[e.from] + e.cost;
	  prev_node[e.to] = e.from;
	  update = true;
	}
      }
    }
    if(update && i == V - 1) return -INF; 
  }
  return dist[t];
}

int main(int argc, char **argv){
  int T;
  cin >> T;
  while(T--){
    int V, E, R;
    scanf("%d %d %d", &V, &E, &R);
    vector<vector<edge> > g(V);
    for(int i = 0; i < E; i++){
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      g[a - 1].push_back(edge(a - 1, b - 1, c));
      g[b - 1].push_back(edge(b - 1, a - 1, c));
    }
    for(int i = 0; i < R; i++){
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      g[a - 1].push_back(edge(a - 1, b - 1, -c));
    }
    if(bellman_ford(g, 0, V - 1) == -INF)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
