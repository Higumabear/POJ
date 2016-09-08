#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <numeric>
#include <algorithm>

using namespace std;

int V; // 頂点数
const int MAX_V = 1000;
vector<int> G[MAX_V]; // グラフのリンクリスト表現
int match[MAX_V]; // マッチングのペア
bool used[MAX_V]; // DFSですでに調べたかのフラグ

 // uとvをつなぐ
void add_edge(int u, int v){
  G[u].push_back(v);
  G[v].push_back(u);
}

// 増加パスをDFSで探す
bool dfs(int v){
  used[v] = true;
  for(int i = 0; i < G[v].size(); i++){
    int u = G[v][i], w =  match[u];
    if(w < 0 || !used[w] && dfs(w)){
      match[v] = u;
      match[u] = v;
      return true;
    }
  }
  return false;
}

// 二部グラフの最大マッチングを求める
int bipartite_matching(){
  int res = 0;
  memset(match, -1, sizeof(match));
  for(int v = 0; v < V; v++){
    if(match[v] < 0){
      memset(used, 0, sizeof(used));
      if(dfs(v)){
        res++;
      }
    }
  }
  return res;
}

int main(int argc, char **argv){
  int N, M;
  while(cin >> N >> M){
    for(int i = 0; i < MAX_V; i++)
      G[i].clear();
      
    V = N + M;
    for(int k = 0; k < N; k++){
      int t;
      cin >> t;
      for(int i = 0; i < t; i++){
	int a;
	cin >> a;
	add_edge(k, N + a - 1);
      }
    }
    cout << bipartite_matching() << endl;
  }
}
