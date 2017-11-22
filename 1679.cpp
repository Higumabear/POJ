// Time-stamp: <Mon Feb 20 22:20:02 東京 (標準時) 2017>
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
#define INF 1 << 23
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

typedef pair<int, int> PII;

pair<int, vector<PII> >
prim(const vector<vector<int> > &g){
  int V = g.size();
  //priority_queue<pair<int, PII> > Q;
  priority_queue<pair<int, PII> ,
  		 vector<pair<int, PII> >,
  		 greater<pair<int, PII> > > Q;

  vector<bool> used(V, false);
  int res = 0;
  vector<PII> edges;

  Q.push(make_pair(0, make_pair(-1, 0)));
  while(!Q.empty()){
    int cost = Q.top().first;
    PII e = Q.top().second; Q.pop();

    int cur = e.second, prev = e.first;
    if(used[cur]) continue;
    used[cur] = true;
    if(prev != -1){
      res += cost;
      edges.push_back(e);
    }
    for(int next = 0; next < V; next++)
      if(!used[next] && g[cur][next] != INF)
  	Q.push(make_pair(g[cur][next], make_pair(cur, next)));
  }
  return make_pair(res, edges);
}

int main(int argc, char **argv){
  int t;
  cin >> t;
  while(t--){
    int V, E; cin >> V >> E;
    vector<vector<int> > g(V, vector<int>(V, INF));
    for(int i = 0; i < E; i++){
      int s, t, c;
      cin >> s >> t >> c;
      g[s - 1][t - 1] = g[t - 1][s - 1] = c;
    }
    pair<int, vector<PII> > mst = prim(g);
    int mincost = mst.first;
    vector<PII> edges = mst.second;
    bool same = false;
    for(int i = 0; i < edges.size(); i++){
      vector<vector<int> > gg = g;
      int from = edges[i].first, to = edges[i].second;
      gg[from][to] = gg[to][from] = INF - 1;
      pair<int, vector<PII> > tmp = prim(gg);
      if(tmp.first <= mincost){
	same = true;
	break;
      }
    }
    if(same) cout << "Not Unique!" << endl;
    else cout << mincost << endl;
  }
  return 0;
}
