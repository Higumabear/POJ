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

int dp[50][1100];

int main(){
  int T;
  cin >> T;
  while(T--){
    int N; cin >> N;
    vector<int> s(N);
    for(int i = 0; i < N; i++) cin >> s[i];

    FILL(dp, INF);
    dp[0][0] = 0;
    for(int i = 0; i < N; i++){
      for(int j = 0; j <= 1000; j++){
	int u = j + s[i], d = j - s[i];
	if(u <= 1000 && max(j, dp[i][j]) < dp[i + 1][u])
	  dp[i + 1][u] = max(j, dp[i][j]);
	if(d >= 0 && max(j, dp[i][j]) < dp[i + 1][d])
	  dp[i + 1][d] = max(j, dp[i][j]);
      }
    }
    if(dp[N][0] == INF) cout << "IMPOSSIBLE" << endl;
    else{
      int v = 0;
      string ans;
      for(int i = N - 1; i >= 0; i--){
	int u = v + s[i], d = v - s[i];
	if(d >= 0 && dp[i][d] <= dp[N][0]){
	  v = d;
	  ans += 'U';
	}else if(u <= 1000 && dp[i][u] <= dp[N][0]){
	  v = u;
	  ans += 'D';
	}
      }
      reverse(ALL(ans));
      cout << ans << endl;
    }
  }
  return 0;
}
