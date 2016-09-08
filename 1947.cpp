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
template<typename A, size_t N, typename T> inline void FILL(A (&array)[N], const T &val){ std::fill( (T*)array, (T*)(array+N), val );}
const double PI  = acos(-1.0);


int dp[200][200];
int parent[200];
vector<int> g[200];

int N, P;
void dfs(int pos){
  for(int i = 2; i <= P; i++) dp[pos][i] = INF;
  if(g[pos].size() == 0) dp[pos][1] = 0;
  for(int i = 0; i < g[pos].size(); i++){
    int y = g[pos][i];
    dfs(y);
    for(int j = P; j >= 1; j--){
      dp[pos][j]++;
      for(int k = 1; k < j; k++)
	dp[pos][j] = min(dp[pos][j], dp[pos][j - k] + dp[y][k]);
    }
  }
}

int main(int argc, char **argv){
  FILL(parent, -1);
  cin >> N >> P;
  for(int i = 0; i < N - 1; i++){
    int s, t;
    cin >> s >> t;
    g[s].push_back(t);
    parent[t] = s;
  }

  int root = 1;
  while(parent[root] != -1) root = parent[root];
  
  dfs(root);
  int ans = dp[root][P];

  for(int i = 1; i <= N; i++)
    ans = min(ans, dp[i][P] + 1);
  cout << ans << endl;
}
