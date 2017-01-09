#include <vector>
#include <iostream>
#include <cstdio>
#include <string.h> // for memset
#include <vector>
using namespace std;
int V; // 頂点数
const int MAX_V = 1000;
vector<int> G[MAX_V]; // グラフのリンクリスト表現
int match[MAX_V]; // マッチングのペア
bool used[MAX_V]; // DFSですでに調べたかのフラグ

 // uとvをつなぐ
void add_edge(int u, int v){
  G[u].push_back(v);
  //G[v].push_back(u);
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

int main(){
  while(scanf("%d", &V) != EOF){
    for(int i = 0; i < MAX_V; i++) G[i].clear();
    for(int i = 0; i < V; i++){
      int from, k;
      scanf("%d: (%d)", &from, &k);
      for(int j = 0; j < k; j++){
	int to; scanf("%d", &to);
	add_edge(from, to);
      }
      getchar();
    }
    printf("%d\n", V - bipartite_matching());
  }
  return 0;
}
