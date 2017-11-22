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

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int H, W;
deque<pair<int, int> > p;
vector<string> f;
int m[20][20];

void bfs(int idx){
  queue<int> Q;
  vector<vector<int> > d(H, vector<int>(W, INF));
  Q.push(p[idx].first * W + p[idx].second);
  d[p[idx].first][p[idx].second] = 0;
  while(!Q.empty()){
    int y = Q.front() / W, x = Q.front() % W;
    Q.pop();
    for(int k = 0; k < 4; k++){
      int ny = y + dy[k], nx = x + dx[k];
      if(0 <= ny && ny < H && 0 <= nx && nx < W &&
	 f[ny][nx] != 'x' && d[ny][nx] == INF){
	d[ny][nx] = d[y][x] + 1;
	Q.push(ny * W + nx);
      }
    }
  }
  for(int i = 0; i < p.size(); i++)
    m[idx][i] = d[p[i].first][p[i].second];
}


ll dp[1 << 11][11];
ll dfs(int S, int idx){
  if(S == ((1 << p.size()) - 1)) return 0;

  ll &ret = dp[S][idx];
  if(ret != -1) return ret;

  ret = INF;
  for(int i = 0; i < p.size(); i++)
    if(!(S >> i & 1))
      ret = min(ret, dfs(S | (1 << i), i) + m[idx][i]);
  return ret;
}

int main(){
  while(cin >> W >> H, H){
    p.clear();
    f.resize(H);
    for(int i = 0; i < H; i++) cin >> f[i];
    for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++){
	if(f[i][j] == 'o') p.push_front(make_pair(i, j));
	else if(f[i][j] == '*') p.push_back(make_pair(i, j));
      }
    }
    int inf = 10000;
    FILL(m, inf);
    for(int i = 0; i < p.size(); i++) bfs(i);

    // for(int i = 0; i < p.size(); i++){
    //   for(int j = 0; j < p.size(); j++){
    // 	cout << m[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    
    FILL(dp, -1);
    ll ans = dfs(1, 0);
    //dump(ans);
    cout << (ans >= INF ? -1 : ans) << endl;
  }
  return 0;
}
