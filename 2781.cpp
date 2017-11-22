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

vector<int> g[100100];

int main(){
  int N;
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    int c, nc;
    scanf("%d %d", &c, &nc);
    for(int j = 0; j < nc; j++){
      int t;
      scanf("%d", &t);
      g[c].push_back(t);
      g[t].push_back(c);
    }
  }

  vector<int> dist(N, -1);
  queue<int> Q;
  int c1, c2;
  scanf("%d %d", &c1, &c2);
  Q.push(c1);
  dist[c1] = 0;
  while(!Q.empty()){
    int v = Q.front(); Q.pop();
    if(v == c2) break;
    for(int i = 0; i < g[v].size(); i++){
      int to = g[v][i];
      if(dist[to] != -1) continue;
      dist[to] = dist[v] + 1;
      Q.push(to);
    }
  }
  printf("%d %d %d\n", c1, c2, dist[c2] - 1);
  return 0;
}
