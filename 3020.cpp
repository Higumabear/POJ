// Time-stamp: <Wed Feb 08 22:05:54 東京 (標準時) 2017>
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

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

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
  int T = 0; cin >> T;
  while(T--){
    int H, W; cin >> H >> W;
    vector<string> f(H);
    for(int i = 0; i < H; i++) cin >> f[i];
    
    G.clear();
    G.resize(H * W);
    int V = 0;
    for(int i = 0; i < H; i++){
      for(int j  = 0; j < W; j++){
	if(f[i][j] == 'o') continue;
	V++;
	for(int k = 0; k < 4; k++){
	  int ny = i + dy[k], nx = j + dx[k];
	  if(0 <= ny && ny < H && 0 <= nx && nx < W && f[ny][nx] == '*'){
	    G[i * W + j].push_back(ny * W + nx);
	    G[ny * W + nx].push_back(i * W + j);
	  }
	}
      }
    }
    cout << V - bipartite_matching() << endl;
  }
  return 0;
}
