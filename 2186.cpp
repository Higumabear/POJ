#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
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

const int MAX_V = 10000;

int V; // 頂点数
vector<int> G[MAX_V]; // グラフの隣接リスト
vector<int> rG[MAX_V];// 逆グラフの隣接リスト
vector<int> vs; // 帰りがけの順番の並び
bool used[MAX_V];
int cmp[MAX_V];

void add_edge(int from, int to){
  G[from].push_back(to);
  rG[to].push_back(from);
}

void dfs(int v){
  used[v] = true;
  for(int i = 0; i < G[v].size(); i++){
    if(!used[G[v][i]]) dfs(G[v][i]);
  }
  vs.push_back(v);
}

void rdfs(int v, int k){
  used[v] = true;
  cmp[v] = k;
  for(int i = 0; i < rG[v].size(); i++){
    if(!used[rG[v][i]]) rdfs(rG[v][i], k);
  }
}


int scc(){
  memset(used, 0, sizeof(used));
  vs.clear();
  for(int v = 0; v < V; v++){
    if(!used[v]) dfs(v);
  }
  
  memset(used, 0, sizeof(used));
  int k = 0;
  for(int i = vs.size() - 1; i >= 0; i--){
    if(!used[vs[i]]) rdfs(vs[i], k++);
  }
  return k;
}

int main(int argc, char **argv){
  int N, M;
  scanf("%d %d", &N, &M);
  V = N;
  for(int i = 0; i < M; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    add_edge(a - 1, b - 1);
  }

  int K = scc();
  int ans = 0, u;
  for(int v = 0; v < V; v++){
    if(cmp[v] == K - 1) {
      u = v;
      ans++;
    }
  }
  FILL(used, false);
  rdfs(u, 0);
  for(int v = 0; v < V; v++)
    if(!used[v]) ans = 0;

  printf("%d\n", ans);
}
