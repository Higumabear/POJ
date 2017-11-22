// Time-stamp: <Wed Mar 22 00:47:52 東京 (標準時) 2017>
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

const int MAXN = 3000;

int pre[110], bottleneck[110];
int flow[110][110], cap[110][110];
int N, np, nc, M;

int bfs(int N, int S, int T)
{
  int result = 0;
  while (1) {
    memset(bottleneck, 0, sizeof(bottleneck));
    queue<int> Q;
    Q.push(S);
    bottleneck[S] = 9999999999;

    while (!Q.empty()) {
      int cur = Q.front(); Q.pop();
      for (int nxt = 0; nxt < N; ++nxt) {
	if (bottleneck[nxt] == 0 && cap[cur][nxt] > flow[cur][nxt]) {
	  Q.push(nxt);
	  pre[nxt] = cur;
	  bottleneck[nxt] = min(bottleneck[cur], cap[cur][nxt] - flow[cur][nxt]);
	}
      }
    }
    if (bottleneck[T] == 0) break;

    for (int cur = T; cur != S; cur = pre[cur]) {
      flow[pre[cur]][cur] += bottleneck[T];
      flow[cur][pre[cur]] -= bottleneck[T];
    }
    result += bottleneck[T];
  }
  return result;
}

int main(int argc, char **argv){
  int N, np, nc, M;
  while(cin >> N >> np >> nc >> M){
    //G.resize(N + 2);
    memset(flow, 0, sizeof(flow));
    memset(cap, 0, sizeof(cap));

    int u, v, f;
    char _;
    for(int i = 0; i < M; i++){
      cin >> _ >> u >> _ >> v >> _ >> f;
      //add_edge(u, v, f);
      cap[u][v] += f;
    }
    for(int i = 0; i < np; i++){
      cin >> _ >> u >> _ >> f;
      //add_edge(N, u, f);
      cap[N][u] += f;
    }
    for(int i = 0; i < nc; i++){
      cin >> _ >> u >> _ >> f;
      //add_edge(u, N + 1, f);
      cap[u][N + 1] += f;
    }
    cout << bfs(N + 2, N, N + 1) << endl;
  }
  return 0;
}
