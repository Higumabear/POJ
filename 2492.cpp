// Time-stamp: <Tue Feb 07 22:02:39 東京 (標準時) 2017>
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

int V;
bool adj[2010][2010];
int col[2010];
bool dfs(int idx, int c){
  col[idx] = c;
  for(int i = 0; i < V; i++){
    if(idx != i && adj[idx][i]){
      if(col[i] == c) return false;
      if(col[i] == -1 && !dfs(i, 1 - c)) return false;
    }
  }
  return true;
}

int main(int argc, char **argv){
  int t;
  scanf("%d", &t);
  for(int i = 1; i <= t; i++){
    memset(adj, false, sizeof(adj));
    memset(col, -1, sizeof(col));
    int m;
    scanf("%d %d", &V, &m);
    for(int j = 0; j < m; j++){
      int s, t;
      scanf("%d %d", &s, &t);
      adj[s - 1][t - 1] = adj[t - 1][s - 1] = true;
    }
    
    bool ret = true;
    for(int j = 0; j < V; j++)
      if(col[j] == -1)
	ret &= dfs(j, 1);
    
    printf("Scenario #%d:\n", i);
    if(!ret) printf("Suspicious bugs found!\n\n");
    else printf("No suspicious bugs found!\n\n");
  }
  return 0;
}
