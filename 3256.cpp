// Time-stamp: <Tue Jan 24 22:25:30 東京 (標準時) 2017>
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

bool pos[1010];
vector<int> edge[1010];

int main(int argc, char **argv){
  int K, N, M, redunt = 0;
  scanf("%d%d%d", &K, &N, &M);
  FILL(pos, false);
  for(int i = 0; i < K; i++){
    int t;
    scanf("%d", &t);
    if(pos[t]) redunt++;
    pos[t] = true;
  }

  for(int i = 0; i < M; i++){
    int s, t;
    scanf("%d %d", &s, &t);
    edge[t].push_back(s);
  }
  
  int ans = 0;
  for(int i = 1; i <= N; i++){
    bool vis[1010] = {false};
    queue<int> q;
    q.push(i);
    int cnt = 0;
    while(!q.empty()){
      int idx = q.front(); q.pop();
      if(vis[idx]) continue;
      vis[idx] = true;
      if(pos[idx]) cnt++;
      for(int j = 0; j < edge[idx].size(); j++)
	q.push(edge[idx][j]);
    }
    if(cnt == K - redunt) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
