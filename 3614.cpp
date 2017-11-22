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

int minSPF[3000], maxSPF[3000];
int SPF[3000], cover[3000];

const int MAXN = 10000;

struct max_flow {
  struct edge { int to, cap, rev; };
  int V;
  vector<vector<edge> > G;
  vector<int> itr, level;

  max_flow(int V) : V(V) { G.assign(V,vector<edge>()); }

  void add_edge(int from, int to, int cap) {
    G[from].push_back((edge) {to, cap, (int) G[to].size()});
    G[to].push_back((edge) {from, 0, (int) G[from].size()-1});
  }

  void bfs(int s) {
    level.assign(V,-1);
    queue<int> q;
    level[s] = 0; q.push(s);
    while (!q.empty()) {
      int v = q.front(); q.pop();
      //for(auto &e: G[v]){
      for(int i = 0; i < G[v].size(); i++){
	edge &e = G[v][i];
	if (e.cap > 0 and level[e.to] < 0) {
	  level[e.to] = level[v] + 1;
	  q.push(e.to);
	}
      }
    }
  }

  int dfs(int v, int t, int f) {
    if (v == t) return f;
    for (int& i = itr[v]; i < (int) G[v].size(); ++i) {
      edge& e = G[v][i];
      if (e.cap > 0 and level[v] < level[e.to]) {
	int d = dfs(e.to, t, min(f, e.cap));
	if (d > 0) {
	  e.cap -= d;
	  G[e.to][e.rev].cap += d;
	  return d;
	}
      }
    }
    return 0;
  }

  int run(int s, int t) {
    int ret = 0, f;
    while (bfs(s), level[t] >= 0) {
      itr.assign(V,0);
      while ((f = dfs(s, t, INF)) > 0) ret += f;
    }
    return ret;
  }
};

int main(){
  int C, L;
  scanf("%d %d", &C, &L);
  
  int S = 2 * C + 2 * L, T = S + 1;
  //G.resize(T + 1);
  max_flow mf(T + 1);

  for(int i = 0; i < C; i++){
    scanf("%d %d", minSPF + i, maxSPF + i);
    mf.add_edge(2 * L + i, 2 * L + C + i, 1);
    mf.add_edge(2 * L + C + i, T, INF);
  }
  
  for(int i = 0; i < L; i++){
    scanf("%d %d", SPF + i, cover + i);
    mf.add_edge(S, i, INF);
    mf.add_edge(i, i + L, cover[i]);
  }

  for(int i = 0; i < L; i++)
    for(int j = 0; j < C; j++)
      if(minSPF[j] <= SPF[i] && SPF[i] <= maxSPF[j])
	mf.add_edge(i + L, 2 * L + j, 1);

  printf("%d\n", mf.run(S, T));
  return 0;
}
