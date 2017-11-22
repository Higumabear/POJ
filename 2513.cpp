#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> g[300000];
int enc[300000];
bool vis[300000];
int V;

int base = 1007;
int mod = 273113;

int ro_hash(char *s){
  int L = strlen(s);
  int hash = 0;
  for(int i = 0; i < L; i++) hash = (hash + s[i]) * base % mod;
  if(enc[hash] != -1) return enc[hash];
  return enc[hash] = V++;
}

void rec(int idx, int prev){
  vis[idx] = true;
  for(int i = 0; i < g[idx].size(); i++)
    if(g[idx][i] != prev && !vis[g[idx][i]])
      rec(g[idx][i], idx);
  return;
}

int main(){
  char s[15], t[15];
  V = 0;
  memset(enc, -1, sizeof(enc));
  memset(vis, false, sizeof(vis));
  while(~scanf("%s %s", s, t)){
    int fr = ro_hash(s);
    int to = ro_hash(t);
    g[fr].push_back(to);
    g[to].push_back(fr);
  }
  
  rec(0, -1);
  if(count(vis, vis + V, false) != 0){
    printf("Impossible\n");
    return 0;
  }

  int odd = 0;
  for(int i = 0; i < V; i++)
    odd += (g[i].size() % 2);
  printf("%s\n", odd <= 2 ? "Possible" : "Impossible");
}
