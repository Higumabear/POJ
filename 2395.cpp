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

using namespace std;

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 61
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;
inline int s2i(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string i2s(T x) {ostringstream sout;sout<<x;return sout.str();}
const double PI  = acos(-1.0);

struct edge {
  int from/*自分*/, to/*行き先*/, flow/*流量*/, cost/*費用*/;
  edge(int from, int to, int flow, int cost) :
    from(from), to(to), flow(flow), cost(cost) {}
  edge(int to, int cost) :
    to(to), cost(cost) {}
  bool operator >(const edge &e) const{
    return cost > e.cost;
  }
  bool operator <(const edge &e) const{
    return cost < e.cost;
  }
};
typedef vector<vector<edge> > Graph;
typedef pair<int, int> P;

int par[2000], uf_rank[2000];

void uf_init(int n){
  for(int i = 0; i < n; i++){
    par[i] = i;
    uf_rank[i] = 0;
  }
}

int uf_find(int x){
  return par[x] == x ? x : par[x] = uf_find(par[x]);
}

void uf_unite(int x, int y){
  x = uf_find(x);
  y = uf_find(y);
  if(x == y) return;

  if(uf_rank[x] < uf_rank[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if(uf_rank[x] == uf_rank[y]) uf_rank[x]++;
  }
}

bool uf_same(int x, int y){
  return uf_find(x) == uf_find(y);
}
// クラスカル法(Not verified)
pair<int, vector<edge> > kruskal(const Graph &g){
  int V = g.size();
  uf_init(V);
  priority_queue<edge, vector<edge>, greater<edge> > Q;
  for(int i = 0; i < V; i++) 
    for(int j = 0; j < (int)g[i].size(); j++)
      if(i < g[i][j].to) Q.push(g[i][j]);

  int total = 0;
  vector<edge> MST;
  while((int)MST.size() < V - 1 && !Q.empty()){
    edge e = Q.top(); Q.pop();
    if(!uf_same(e.from, e.to)){
      uf_unite(e.from, e.to);
      MST.push_back(e);
      total += e.cost;
    }
  }
  return pair<int, vector<edge> >(total, MST);
}


int main(){
  int N, M;
  Graph g;
  scanf("%d %d", &N, &M);
  g.resize(N);
  uf_init(2000);
  for(int i = 0; i < M; i++){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    a--, b--;
    edge e(a, b, 0, c);
    edge f(b, a, 0, c);
    g[a].push_back(e);
    g[b].push_back(f);
  }
  pair<int, vector<edge>> mst = kruskal(g);

  vector<edge> t = mst.second;
  int ans = 0;
  for(int i = 0; i < (int)t.size(); i++) ans = max(ans, t[i].cost);
  cout << ans << endl;
  return 0;
}