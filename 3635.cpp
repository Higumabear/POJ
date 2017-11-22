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

int p[1001];
vector<pair<int, int> > g[1000];
bool vis[1001][103];

void solve(){
  int c, s, e;
  cin >> c >> s >> e;
  FILL(vis, false);
  priority_queue<pair<int, pair<int, int> > > q;
  q.push(make_pair(0, make_pair(s, 0)));

  while(!q.empty()){
    int cc = -q.top().first;
    int tv = q.top().second.first;
    int cap = q.top().second.second;
    q.pop();
    if(tv == e){
      cout << cc << endl;
      return;
    }
    if(vis[tv][cap]) continue;
    vis[tv][cap] = true;
    if(cap < c && !vis[tv][cap + 1])
      q.push(make_pair(-cc-p[tv], make_pair(tv, cap + 1)));

    for(int i = 0; i < g[tv].size(); i++){
      int to = g[tv][i].first;
      int d = g[tv][i].second;
      if(d > cap || vis[to][cap - d])continue;
      q.push(make_pair(-cc, make_pair(to, cap - d)));
    }
  }
  cout << "impossible" << endl;
}

int main(){
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    cin >> p[i];

  for(int i = 0; i < m; i++){
    int u, v, d;
    cin >> u >> v >> d;
    g[u].push_back(make_pair(v, d));
    g[v].push_back(make_pair(u, d));
  }

  int q;
  cin >> q;
  while(q--)
    solve();
  
  return 0;
}
