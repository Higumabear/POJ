#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int MAXN = 20002;
const int INF = 1 << 29;

int N;
vector<int> g[MAXN];
bool check[MAXN];

int ans, ans_idx;

int rec(int idx, int prev){
  int ret = 1;
  int bal = 0;
  for(int i = 0; i < g[idx].size(); i++){
    int to = g[idx][i];
    if(to != prev){
      int subtree = rec(to, idx);
      ret += subtree;
      bal = max(bal, subtree);
    }
  }
  bal = max(bal, N - ret);

  if(bal < ans){
    ans_idx = idx;
    ans = bal;
  }
  return ret;
}

int main(){
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%d", &N);
    for(int i = 0; i <= N; i++) g[i].clear();
    for(int i = 0; i < N - 1; i++){
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    ans = INF;
    ans_idx = -1;
    rec(1, -1);
    printf("%d %d\n", ans_idx, ans);
  }
}
