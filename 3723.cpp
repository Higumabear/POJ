// Time-stamp: <Tue Mar 21 21:48:13 東京 (標準時) 2017>
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
  //edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
  bool operator<(const edge &r) const{ return cost < r.cost; }
  bool operator>(const edge &r) const{ return cost > r.cost; }
};

edge es[60000];

int kruscal(int V, int E){
  sort(es, es + E);
  int sum = 0;
  UnionFind uf(V);
  for(int i = 0; i < E; i++){
    edge e = es[i];
    if(!uf.same(e.from, e.to)){
      sum += e.cost;
      uf.unite(e.from, e.to);
    }
  }
  return sum;
}


int main(int argc, char **argv){
  int T;
  scanf("%d", &T);
  while(T--){
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);

    for(int i = 0; i < q; i++){
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      es[i] = (edge){a, b + n, -c};
    }
    printf("%d\n", 10000 * (n + m) + kruscal(n + m, q));
  }
  return 0;
}
