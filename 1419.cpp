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

vector<int> g[100];
 
int main(){
  int T;
  cin >> T;
  while(T--){
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < K; i++){
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    vector<bool> ans;
    for(int i = 0; i < N; i++){
      queue<int> Q;
      Q.push(i);
      vector<bool> vis(N, false), use(N, false);
      vis[i] = true;
      use[i] = true;
      while(!Q.empty()){
	int v = Q.front(); Q.pop();
	use[v] = true;
	for(int j = 0; j < g[v].size(); j++){
	  int u = g[v][j];
	  if(use[u]) use[v] = false;
	  if(!vis[u]){
	    vis[u] = true;
	    Q.push(u);
	  }
	}
      }
      if(count(ALL(ans), true) < count(ALL(use), true)) ans = use;
    }
    cout << count(ALL(ans), true) << endl;
    for(int i = 0; i < ans.size(); i++)
      if(ans[i]) cout << i + 1 << " ";
    cout << endl;
  }
  return 0;
}
