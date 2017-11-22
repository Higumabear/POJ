// Time-stamp: <Thu Jul 27 01:18:52 東京 (標準時) 2017>
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

double gx[100], gy[100], hx[100], hy[100];
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
  int n, m, s, v;
  while(cin >> n >> m >> s >> v){
    for(int i = 0; i < n; i++) cin >> gx[i] >> gy[i];
    for(int i = 0; i < m; i++) cin >> hx[i] >> hy[i];

    G.clear();
    G.resize(n + m);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
	double d = sqrt(pow(gx[i] - hx[j], 2.0) + pow(gy[i] - hy[j], 2.0));
	if(d / v < s){
	  G[i].push_back(n + j);
	  G[n + j].push_back(i);
	}
      }
    }
    cout << n - bipartite_matching() << endl;
  }
  return 0;
}
