// Time-stamp: <Sun Feb 12 00:31:47 東京 (標準時) 2017>
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
int prev_node[100100];
int dist[100100];
int dijkstra(vector<vector<edge> > g, int s, int t){
  int V = g.size();
  priority_queue<edge, vector<edge>, greater<edge> > Q;
  Q.push(edge(-2, s, 0));
  fill(dist, dist + 100100, INF);
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
  int F, P, C, M;
  cin >> F >> P >> C >> M;
  g.resize(F);
  for(int i = 0; i < P; i++){
    int s, t, c;
    cin >> s >> t >> c;
    s--, t--;
    add_edge(s, t, c);
  }
  dijkstra(g, 0, F - 1);

  vector<int> ans;
  for(int i = 0; i < C; i++){
    int x;
    cin >> x;
    if(dist[x - 1] <= M) ans.push_back(i + 1);
  }
  sort(ALL(ans));
  cout << ans.size() << endl;
  for(int i = 0; i < ans.size(); i++)
    cout << ans[i] << endl;
  return 0;
}
