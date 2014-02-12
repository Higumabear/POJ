#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;

const int INF = 100000000;

struct edge {
  int from/*自分*/, to/*行き先*/, flow/*流量*/, cost/*費用*/;
  edge(int from, int to, int flow, int cost) :
    from(from), to(to), flow(flow), cost(cost) {}
  bool operator >(const edge &e) const{
    return cost > e.cost;
  }
  bool operator <(const edge &e) const{
    return cost < e.cost;
  }
};

typedef vector<vector<edge> > Graph;
typedef pair<int, int> P;

int dist[10000];
void dijkstra(const Graph &g, int s){
  int V = g.size();
  fill(dist, dist + V, INF);
  dist[s] = 0;
  priority_queue<P, vector<P>, greater<P> > Q;
  Q.push(P(0, s));
  while(!Q.empty()){
    P p = Q.top(); Q.pop();
    int v = p.second;
    if(dist[v] < p.first) continue;
    for(int i = 0; i < (int)g[v].size(); i++){
      edge e = g[v][i];
      if(dist[e.to] > dist[v] + e.cost){
	dist[e.to] = dist[v] + e.cost;
	Q.push(P(dist[e.to], e.to));
      }
    }
  }
}


int main(){
  int T, N;
  cin >> T >> N;
  Graph g(N);
  for(int i = 0; i < T; i++){
    int a,b,c;
    cin >> a >> b >> c;
    g[a - 1].push_back(edge(0, b - 1, 0, c));
    g[b - 1].push_back(edge(0, a - 1, 0, c));
  }
  dijkstra(g, 0);
  cout << dist[N - 1] << endl;
  return 0;
}