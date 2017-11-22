// Time-stamp: <Thu Apr 27 00:27:53 東京 (標準時) 2017>
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

bool f[201][201];

const int MAXN = 1000;

vector<vector<int> > G; //bidirection

bool augment(int u, 
	     vector<int> &match, vector<bool> &vis){
  vis[u] = true;
  for(int i = 0; i < G[u].size(); i++){
    int v = G[u][i], w = match[v];
    if(w == -1 || (!vis[w] && augment(w, match, vis))){
      match[u] = v, match[v] = u;
      return true;
    }
  }
  return false;
}

int bipartite_matching(){
  int V = G.size(), ret = 0;
  vector<int> match(V, -1);
  for(int i = 0; i < V; i++){
    if(match[i] != -1) continue;
    vector<bool> vis(V, false);
    if(augment(i, match, vis)) ret++;
  }
  return ret;
}

int main(int argc, char **argv){
  int g, b, m;
  int idx = 0;
  while(scanf("%d %d %d", &g, &b, &m), g){
    FILL(f, false);
    int s, t;
    for(int i = 0; i < m; i++){
      scanf("%d %d", &s, &t);
      f[s - 1][t - 1] = true;
    }
    G.clear();
    G.resize(g + b);
    for(int i = 0; i < g; i++){
      for(int j = 0; j < b; j++){
	if(f[i][j]) continue;
	//printf("%d -> %d\n", i, j);
	G[i].push_back(g + j);
	G[g + j].push_back(i);
      }
    }
    printf("Case %d: %d\n", ++idx, g + b - bipartite_matching());
  }
  
  return 0;
}
