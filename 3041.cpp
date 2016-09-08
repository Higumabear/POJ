// Time-stamp: <Thu Aug 04 21:23:18 東京 (標準時) 2016>
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
  int N, K;
  cin >> N >> K;
  V = 2 * N;
  for(int i = 0; i < K; i++){
    int y, x;
    cin >> y >> x;
    y--, x--;
    add_edge(y, x + N);
  }
  cout << bipartite_matching() << endl;
  return 0;
}
