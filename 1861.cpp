// Time-stamp: <Tue Nov 29 23:09:36 東京 (標準時) 2016>
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

class UnionFind{
public:
  UnionFind();
  UnionFind(int num){
    for(int i = 0; i < num; i++) parent[i] = i, rank[i] = 0;
  }

  bool same (int x, int y) { return find(x) == find(y); }
  void unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return;
    if(rank[y] > rank[x]){
      parent[x] = y;
    }else{
      parent[y] = x;
      if(rank[x] == rank[y]) rank[x]++;
    }
  }

private:
  int rank[200001], parent[200001];

  int find(int x){
    while(x != parent[x]) x = parent[x];
    return x;
  }
};

struct edge{
  int from, to, cost;
  edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
  bool operator<(const edge &r) const{ return cost < r.cost; }
  bool operator>(const edge &r) const{ return cost > r.cost; }
};

vector<vector<edge> > g;

void add_edge(int from, int to, int cost){//2way
  g[from].push_back(edge(from, to, cost));
  g[to].push_back(edge(to, from, cost));
}

pair<int, vector<edge> > kruscal(vector<vector<edge> > g){
  int V = g.size();
  priority_queue<edge, vector<edge>, greater<edge> > Q;

  for(int i = 0; i < V; i++)
    for(int j = 0; j < g[i].size(); j++)
      if(i < g[i][j].to) Q.push(g[i][j]);

  int sum = 0;
  vector<edge> mst;
  UnionFind uf(V);
  for(int i = 0; i < V - 1; i++){
    edge e = Q.top(); Q.pop();
    if(uf.same(e.from, e.to)) i--;
    else{
      sum += e.cost;
      mst.push_back(e);
      uf.unite(e.from, e.to);
    }
  }
  return make_pair(sum, mst);
}

int main(int argc, char **argv){
  int N, M;
  scanf("%d %d", &N, &M);
  g.resize(N);
  for(int i = 0; i < M; i++){
    int s, t, cost;
    scanf("%d %d %d", &s, &t, &cost);
    add_edge(s - 1, t - 1, cost);
  }
  pair<int, vector<edge> > mst = kruscal(g);
  vector<edge> e = mst.second;

  int maxv = 0;
  for(int i = 0; i < e.size(); i++) 
    maxv = max(maxv, e[i].cost);
  cout << maxv << endl;
  cout << e.size() << endl;
  for(int i = 0; i < e.size(); i++)
    cout << e[i].from + 1 << " " << e[i].to + 1 << endl;
  return 0;
}
