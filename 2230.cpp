#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<pair<int, int> > g[10000];
bool vis[50000];

void rec(int idx){
  printf("%d\n", idx + 1);
  for(int i = 0; i < g[idx].size(); i++){
    if(vis[g[idx][i].second]) continue;
    vis[g[idx][i].second] = true;
    rec(g[idx][i].first);
    printf("%d\n", idx + 1);
  }
  return;
}

int main(int argc, char **argv){
  int N, M;
  scanf("%d %d", &N, &M);
  for(int i = 0; i < M; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    a--, b--;
    g[a].push_back(make_pair(b, i));
    g[b].push_back(make_pair(a, i));
  }
  rec(0);
}

