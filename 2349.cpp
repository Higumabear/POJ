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
  int from, to; double cost;
  edge(int from, int to, double cost) : from(from), to(to), cost(cost) {}
  bool operator<(const edge &r) const{ return cost < r.cost; }
  bool operator>(const edge &r) const{ return cost > r.cost; }
};

vector<vector<edge> > g;
int S, P;

void add_edge(int from, int to, double cost){//2way
  g[from].push_back(edge(from, to, cost));
  g[to].push_back(edge(to, from, cost));
}

double kruscal(vector<vector<edge> > g){
  int V = g.size();
  priority_queue<edge, vector<edge>, greater<edge> > Q;

  for(int i = 0; i < V; i++)
    for(int j = 0; j < g[i].size(); j++)
      if(i < g[i][j].to) Q.push(g[i][j]);

  UnionFind uf(V);
  for(int i = 0; i < V - 1; i++){
    edge e = Q.top(); Q.pop();
    if(uf.same(e.from, e.to)) i--;
    else{
      if(i == V - S - 1) return e.cost;
      uf.unite(e.from, e.to);
    }
  }
  return -1.0;
}

int x[501], y[501];

int main(int argc, char **argv){
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%d %d", &S, &P);

    g.clear();
    g.resize(P);
    for(int i = 0; i < P; i++)
      scanf("%d %d", x + i, y + i);

    for(int i = 0; i < P; i++){
      for(int j = i + 1; j < P; j++){
	double r = sqrt(1.0 * (x[i] - x[j]) * (x[i] - x[j])
			+ 1.0 * (y[i] - y[j]) * (y[i] - y[j]));
	add_edge(i, j, r);
      }
    }
    printf("%.2f\n", kruscal(g));
  }
}
