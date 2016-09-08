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

using namespace std;

int par[60000], uf_rank[60000];

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

int main(int argc, char **argv){
  int n, m, idx = 0;
  while(1){
    scanf("%d %d", &n, &m);
    if(n == 0 && m == 0) break;
    idx++;
    uf_init(n + 100);

    int a, b;
    for(int i = 0; i < m; i++){
      scanf("%d %d", &a, &b);
      uf_unite(a, b);
    }
    
    set<int> p;
    for(int i = 1; i <= n; i++) p.insert(uf_find(i));
    printf("Case %d: %d\n", idx, p.size());
  }
  return 0;
}