// Time-stamp: <Thu Mar 30 01:31:34 東京 (標準時) 2017>
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

double X[1010], Y[1010];
int from[1010], to[1010];
int n, q;

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
  int rank[1010], parent[1010];

  int find(int x){
    while(x != parent[x]) x = parent[x];
    return x;
  }
};

struct edge{
  int from, to;
  double cost;
  edge(int from, int to, double cost) : from(from), to(to), cost(cost) {}
  bool operator<(const edge &r) const{ return cost < r.cost; }
  bool operator>(const edge &r) const{ return cost > r.cost; }
};

// vector<vector<edge> > g;

// void add_edge(int from, int to, double cost){//2way
//   g[from].push_back(edge(from, to, cost));
//   g[to].push_back(edge(to, from, cost));
// }

double g[1010][1010];

double kruscal(){
  int V = n;
  priority_queue<edge, vector<edge>, greater<edge> > Q;

  for(int i = 0; i < V; i++)
    for(int j = i + 1; j < V; j++)
      Q.push(edge(i, j, g[i][j]));

  double sum = 0;
  UnionFind uf(V);
  for(int i = 0; i < q; i++)
    uf.unite(from[i] - 1, to[i] - 1);

  while(!Q.empty()){
    edge e = Q.top(); Q.pop();
    if(!uf.same(e.from, e.to)){
      sum += e.cost;
      uf.unite(e.from, e.to);
    }
  }
  return sum;
}

int main(int argc, char **argv){
  scanf("%d %d", &n, &q);
  for(int i = 0; i < n; i++)
    scanf("%lf %lf", X + i, Y + i);
  
  FILL(g, 1e100);
  for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
      double d = sqrt((X[i] - X[j]) * (X[i] - X[j]) + 
		      (Y[i] - Y[j]) * (Y[i] - Y[j]));
      g[i][j] = g[j][i] = d;
    }
  }
  
  for(int i = 0; i < q; i++)
    scanf("%d %d", from + i, to + i);

  printf("%.2f\n", kruscal());
}
