// Time-stamp: <Wed Apr 12 01:42:40 東京 (標準時) 2017>
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

const int MAX_V = 20010;

struct edge{ 
  int to, cap, rev;
  edge(int to, int cap, int rev) : to(to), cap(cap), rev(rev) {};
};

vector<edge> G[MAX_V];
int level[MAX_V]; // sからの距離
int iter[MAX_V]; // どこまで調べ終わったか

int min(int a, int b){
  return (a > b) ? b : a;
}

void add_edge(int from, int to, int cap){
  G[from].push_back(edge(to, cap, G[to].size()));
  G[to].push_back(edge(from, 0, G[from].size() - 1));
}

// sからの最短距離をBFSで計算する
void bfs(int s){
  memset(level, -1, sizeof(level));
  queue<int> que;
  level[s] = 0;
  que.push(s);
  while(!que.empty()){
    int v = que.front(); que.pop();
    for(int i = 0; i < (int)G[v].size(); i++){
      edge &e = G[v][i];
      if(e.cap > 0 && level[e.to] < 0){
        level[e.to] = level[v] + 1;
        que.push(e.to);
      }
    }
  }
}

// 増加パスをDFSで探す
int dfs(int v, int t, int f){
  if(v == t) return f;
  for(int &i = iter[v]; i < (int)G[v].size(); i++){
    edge &e = G[v][i];
    if(e.cap > 0 && level[v] < level[e.to]){
      int d = dfs(e.to, t, min(f, e.cap));
      if(d > 0){
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}


int max_flow(int s, int t){
  int flow = 0;
  for(;;){
    bfs(s);
    if(level[t] < 0) return flow;
    memset(iter, 0, sizeof(iter));
    int f;
    while((f = dfs(s, t, INF)) > 0){
      flow += f;
    }
  }
}

int main(int argc, char **argv){
  int N, M;
  scanf("%d %d", &N, &M);

  int s = N, t = s + 1;
  //G.resize(N + 2);
  
  int a, b, u, v, c;
  for(int i = 0; i < N; i++){
    scanf("%d %d", &a, &b);
    add_edge(s, i, b);
    add_edge(i, t, a);
  }
  
  for(int i = 0; i < M; i++){
    scanf("%d %d %d", &u, &v, &c);
    add_edge(u - 1, v - 1, c);
    add_edge(v - 1, u - 1, c);
  }

  printf("%d\n", max_flow(s, t));
  return 0;
}
