// Time-stamp: <Sat Feb 25 02:04:20 東京 (標準時) 2017>
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

struct min_cost_flow{
  struct edge{
    int to, cap, cost, rev;
    edge(int to, int cap, int cost, int rev) : 
      to(to), cap(cap), cost(cost), rev(rev) {};
  };
  vector<vector<edge> > G;

  min_cost_flow(int V) : G(V) {}

  void add_edge(int from, int to, int cap, int cost){
    G[from].push_back(edge(to, cap, cost, G[to].size()));
    G[to].push_back(edge(from, 0, -cost, G[from].size() - 1));
  }

  int flow(int s, int t, int f){
    typedef pair<int, int> P;
    int V = G.size();
    vector<int> po(V);
    int res = 0;
    while(f > 0){
      vector<int> dist(V, INF), prevv(V, -1), preve(V, -1);
      priority_queue<P, vector<P>, greater<P> > Q;
      Q.push(make_pair(0, s));
      dist[s] = 0;
      while(!Q.empty()){
	P q = Q.top(); Q.pop();
	int u = q.second;
	if(dist[u] < q.first) continue;
	for(int i = 0; i < G[u].size(); i++){
	  edge &e = G[u][i];
	  if(e.cap > 0 && dist[e.to] > dist[u] + e.cost + po[u] - po[e.to]){
	    dist[e.to] = dist[u] + e.cost + po[u] - po[e.to];
	    prevv[e.to] = u;   preve[e.to] = i;
	    Q.push(P(dist[e.to], e.to));
	  }
	}
      }
      if(dist[t] == INF) return -1;
      for(int v = 0; v < V; v++) po[v] += dist[v];
      
      int scap = f;
      for(int v = t; v != s; v = prevv[v])
	scap = min(scap, G[prevv[v]][preve[v]].cap);
      
      f -= scap;
      res += scap * po[t];
      for(int v = t; v != s; v = prevv[v]){
	edge &e = G[prevv[v]][preve[v]];
	e.cap -= scap;
	G[v][e.rev].cap += scap;
      }
    }
    return res;
  }
};

int main(){
  int v, e;
  cin >> v >> e;
  min_cost_flow mcf(v);

  int s, t, d;
  while(e--){
    cin >> s >> t >> d;
    mcf.add_edge(s - 1, t - 1, 1, d);
    mcf.add_edge(t - 1, s - 1, 1, d);
  }
  cout << mcf.flow(0, v - 1, 2) << endl;
  return 0;
}
