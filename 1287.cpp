#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 61
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;
inline int s2i(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string i2s(T x) {ostringstream sout;sout<<x;return sout.str();}
template<typename A, size_t N, typename T> inline void FILL(A (&array)[N], const T &val){ std::fill( (T*)array, (T*)(array+N), val );}
const double PI  = acos(-1.0);


// struct edge {
//   int from/*自分*/, to/*行き先*/, flow/*流量*/, cost/*費用*/;
//   edge(int from, int to, int flow, int cost) :
//     from(from), to(to), flow(flow), cost(cost) {}
//   edge(int to, int cost) :
//     to(to), cost(cost) {}
//   bool operator >(const edge &e) const{
//     return cost > e.cost;
//   }
//   bool operator <(const edge &e) const{
//     return cost < e.cost;
//   }
// };

// typedef vector<vector<edge> > Graph;


// class UnionFind{
//   int numOfUnion;
//   int par[10000], rank[10000];
//   bool visit[10000];

// public:
  
//   void init(int n){
//     numOfUnion = 0;
//     for(int i = 0; i < n; i++) 
//       par[i] = i, rank[i] = 0, visit[i] = false;
//   }

//   int find(int x){
//     return par[x] == x ? x : par[x] = find(par[x]);
//   }

//   bool same(int x, int y){
//     return find(x) == find(y);
//   }

//   void unite(int x, int y){
//     x = find(x); y = find(y);
//     if(x == y) return;
//     if(rank[x] < rank[y]){
//       par[x] = y;
//     }else{
//       par[y] = x;
//       if(rank[x] == rank[y]) rank[x]++;
//     }
//   }
// };


// // クラスカル法(Not verified)
// pair<int, vector<edge> > kruskal(const Graph &g){
//   int V = g.size();
//   priority_queue<edge> Q;
//   for(int i = 0; i < V; i++) 
//     for(int j = 0; j < (int)g[i].size(); j++)
//       if(i < g[i][j].to) Q.push(g[i][j]);

//   UnionFind uf;
//   uf.init(1000);
  
//   int total = 0;
//   vector<edge> MST;
//   while((int)MST.size() < V - 1 && !Q.empty()){
//     edge e = Q.top(); Q.pop();
//     if(!uf.same(e.from, e.to)){
//       uf.unite(e.from, e.to);
//       MST.push_back(e);
//       total += e.cost;
//     }
//   }
//   return pair<int, vector<edge> >(total, MST);
// }

int prim(vector<vector<int>> dist){
  int N = dist.size();
  vector<bool> used(N, false);
  int ret = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
  Q.push(make_pair(0, 0));
  while(!Q.empty()){
    int cost = Q.top().first;
    int to = Q.top().second;
    Q.pop();
    if(used[to]) continue;
    used[to] = true;
    ret += cost;
    for(int i = 0; i < N; i++) Q.push(make_pair(dist[to][i], i));
  }
  return ret;
}


int main(int argc, char **argv){
  int V, T;
  while(cin >> V, V){
    cin >> T;
    vector<vector<int>> d(V, vector<int>(V, INF));
    for(int i = 0; i < T; i++){
      int a, b, c;
      cin >> a >> b >> c;
      // edge e(a - 1, b - 1, 0, c);
      // //e.to = b - 1, e.cost = c;
      // g[a - 1].push_back(e);
      d[a - 1][b - 1] = min(d[a - 1][b - 1], c);
      d[b - 1][a - 1] = min(d[b - 1][a - 1], c);
    }
    // pair<int, vector<edge>> Q = kruskal(g);
    // cout << Q.first << endl;
    cout << prim(d) << endl;
  }
}
