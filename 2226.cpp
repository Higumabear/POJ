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

int main(){
  int R, C;
  cin >> R >> C;
  G.resize(2 * R * C);
  vector<string> f(R);
  for(int i = 0; i < R; i++) cin >> f[i];

  for(int i = 0; i < R; i++){
    for(int j = 0; j < C; j++){
      if(f[i][j] == '.') continue;

      int k = i, l = j;
      while(k && f[k - 1][j] == '*') k--;
      while(l && f[i][l - 1] == '*') l--;
      G[k * C + j].push_back(R * C + i * C + l);
      G[R * C + i * C + l].push_back(k * C + j);
    }
  }
  cout << bipartite_matching() << endl;
  return 0;
}
