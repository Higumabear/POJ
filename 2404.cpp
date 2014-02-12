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
#include <cstring>
#include <numeric>
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;
const int INF = 114514810;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()


typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;


Weight chinesePostman(const Graph &g) {
  Weight total = 0;
  vector<int> odds;
  REP(u, g.size()) {
    FOR(e, g[u]) total += e->weight;
    if (g[u].size() % 2) odds.push_back(u);
  }
  total /= 2;
  int n = odds.size(), N = 1 << n;
  Weight w[n][n]; // make odd vertices graph
  REP(u,n) {
    int s = odds[u]; // dijkstra's shortest path
    vector<Weight> dist(g.size(), INF); dist[s] = 0;
    vector<int>    prev(g.size(), -2);
    priority_queue<Edge> Q;
    Q.push( Edge(-1, s, 0) );
    while (!Q.empty()) {
      Edge e = Q.top(); Q.pop();
      if (prev[e.dst] != -2) continue;
      prev[e.dst] = e.src;
      FOR(f,g[e.dst]) {
        if (dist[f->dst] > e.weight+f->weight) {
          dist[f->dst] = e.weight+f->weight;
          Q.push(Edge(f->src, f->dst, e.weight+f->weight));
        }
      }
    }
    REP(v,n) w[u][v] = dist[odds[v]];
  }
  Weight best[N]; // DP for general matching 
  REP(S,N) best[S] = INF;
  best[0] = 0;
  


  for (int S = 0; S < N; ++S)
    for (int i = 0; i < n; ++i) if (!(S&(1<<i)))
				  for (int j = i+1; j < n; ++j) if (!(S&(1<<j)))
								  best[S|(1<<i)|(1<<j)] = min(best[S|(1<<i)|(1<<j)], best[S]+w[i][j]);
  return total + best[N-1];
}

int main(){
  int n, m;
  while(cin >> n >> m, n){  
    Graph g(n);
    for(int i = 0; i < m; i++){
      int a, b, c;
      cin >> a >> b >> c;
      a--; b--;
      g[a].push_back(Edge(a,b,c));
      g[b].push_back(Edge(b,a,c));
    }
    cout << chinesePostman(g) << endl;
  }
  return 0;
}