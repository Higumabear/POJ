// Time-stamp: <Thu Mar 02 22:08:55 東京 (標準時) 2017>
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

struct lca{
  vector<vector<int> > g, parent;
  vector<int> depth;
  int K, V;
  lca(int V): g(V), depth(V), V(V) {
    K = 32;
    parent.assign(V, vector<int>(K, -1));
  }
  
  void add_edge(int par, int ch){ g[par].push_back(ch); }
  
  void build(int cur, int prev = 0, int d = 0){
    int k = 1;
    depth[cur] = d;
    parent[cur][0] = prev;
    for(int base = 2; base <= d; base *= 2){
      parent[cur][k] = parent[parent[cur][k - 1]][k - 1];
      k++;
    }
    for(int i = 0; i < g[cur].size(); i++)
      build(g[cur][i], cur, d + 1);
    return;
  }

  int search(int u, int v){
    if(depth[u] > depth[v]) swap(u, v);
    for(int k = 0; k < K; k++)
      if((depth[v] - depth[u]) >> k & 1)
	v = parent[v][k];
    
    if(u == v) return u;
    for(int k = K - 1; k >= 0; k--){
      if(parent[u][k] != parent[v][k]){
	u = parent[u][k];
	v = parent[v][k];
      }
    }
    return parent[u][0];
  }
};

int deg[11000];

int main(int argc, char **argv){
  int T;
  scanf("%d", &T);
  while(T--){
    int N;
    scanf("%d", &N);
    lca g(N);
    fill(deg, deg + N + 100, true);

    int s, t;
    for(int i = 0; i < N - 1; i++){
      scanf("%d %d", &s, &t);
      g.add_edge(s - 1, t - 1);
      deg[t - 1] = false;
    }
    int root;
    for(root = 0; !deg[root]; root++);
    
    g.build(root);
    scanf("%d %d", &s, &t);
    printf("%d\n", g.search(s - 1, t - 1) + 1);
  }
  return 0;
}
