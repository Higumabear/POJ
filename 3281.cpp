// Time-stamp: <Mon Apr 10 21:47:52 東京 (標準時) 2017>
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

const int MAXN = 1000;


struct edge{
  int to, cap, rev;
  edge(int to, int cap, int rev) : to(to), cap(cap), rev(rev) {};
};

int prev[MAXN];
vector<vector<edge> > G;

void add_edge(int from, int to, int cap){
  G[from].push_back(edge(to, cap, G[to].size()));
  G[to].push_back(edge(from, 0, G[from].size() - 1));
}

int edmonds_karp(int s, int t){
  int minflow = 0;
  int V = G.size();
  vector<vector<int> > flow(V, vector<int>(V, 0)),  cap(V, vector<int>(V, 0));
  for(int i = 0; i < V; i++)
    for(int j = 0; j < G[i].size(); j++)
      cap[i][G[i][j].to] += G[i][j].cap;
  
  for(;;){
    queue<int> q;
    q.push(s);
    memset(prev, -1, sizeof(prev));
    prev[s] = s;
    while(!q.empty()){
      int u = q.front(); q.pop();
      if(u == t) break;
      for(int i = 0; i < G[u].size(); i++){
	edge e = G[u][i];
	if(prev[e.to] == -1 
	   && cap[u][e.to] - flow[u][e.to] > 0){
	  q.push(e.to);
	  prev[e.to] = u;
	}
      }
    }
    if(prev[t] == -1) break;

    int minaug = INF;
    for(int v = t; v != prev[v]; v = prev[v]) 
      minaug = min(minaug, cap[prev[v]][v] - flow[prev[v]][v]);
    for(int v = t; v != prev[v]; v = prev[v]) 
      flow[prev[v]][v] += minaug, flow[v][prev[v]] -= minaug;
    minflow += minaug;
  }
  
  return minflow;
}


int main(){
  int N, F, D;
  cin >> N >> F >> D;

  int V = 2 * N + F + D + 2;
  int s = V - 2, t = V - 1;
  G.resize(V);

  for(int j = 0; j < N; j++){
    int f, d, a;
    cin >> f >> d;
    for(int i = 0; i < f; i++){
      cin >> a;
      add_edge(a - 1, j + F, 1);
    }
    for(int i = 0; i < d; i++){
      cin >> a;
      add_edge(j + F + N, F + 2 * N + a - 1, 1);
    }
  }
  for(int i = 0; i < N; i++)
    add_edge(i + F, i + F + N, 1);
  for(int i = 0; i < F; i++)
    add_edge(s, i, 1);
  for(int i = 0; i < D; i++)
    add_edge(F + 2 * N + i, t, 1);

  cout << edmonds_karp(s, t) << endl;
  return 0;
}
