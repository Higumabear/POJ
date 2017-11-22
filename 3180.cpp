// Time-stamp: <Wed Nov 08 16:02:05 太平洋標準時 2017>
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

struct scc{
  int V, c;
  vector<vector<int> > g, rg;
  vector<int> ord;
  vector<int> cmp;
  vector<bool> vis;
  scc(int V) : V(V), g(V), rg(V), ord(V, -1), 
	       cmp(V, -1), vis(V), c(0) {}
  
  void add_edge(int from, int to){
    g[from].push_back(to);
    rg[to].push_back(from);
  }

  void dfs(int i){
    vis[i] = true;
    for(int j = 0; j < g[i].size(); j++)
      if(!vis[g[i][j]]) dfs(g[i][j]);
    ord[c++] = i;
  }
  void rdfs(int i, int label){
    vis[i] = true;
    cmp[i] = label;
    for(int j = 0; j < rg[i].size(); j++) 
      if(!vis[rg[i][j]]) rdfs(rg[i][j], label);
  }

  int decomp(){
    int res = 0;
    fill(vis.begin(), vis.end(), false);
    for(int i = 0; i < V; i++)
      if(!vis[i]) dfs(i);
    
    fill(vis.begin(), vis.end(), false);
    for(int i = c - 1; i >= 0; i--)
      if(!vis[ord[i]]) rdfs(ord[i], res++);
    return res;
  }
};

int main(){
  int V, E;
  scanf("%d %d", &V, &E);
  
  scc scc(V);
  for(int i = 0; i < E; i++){
    int s, t;
    scanf("%d %d", &s, &t);
    scc.add_edge(s - 1, t - 1);
  }
  scc.decomp();

  map<int, int> f;
  for(int i = 0; i < V; i++)
    f[scc.cmp[i]]++;

  int ans = 0;
  map<int, int>::iterator it = f.begin();
  for(; it != f.end(); it++)
    if(it->second >= 2) ans++;
  printf("%d\n", ans);
}
