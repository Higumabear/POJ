// Time-stamp: <Sun Dec 18 18:03:46 東京 (標準時) 2016>
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

ll dp[121][121][2];
int main(int argc, char **argv){
  int T;
  cin >> T;
  FILL(dp, 0);
  dp[1][0][0] = dp[1][0][1] = 1;
  for(int i = 2; i < 120; i++){
    for(int j = 0; j < 120; j++){
      dp[i][j][0] += dp[i - 1][j][0] + dp[i - 1][j][1];
      dp[i][j][1] += dp[i - 1][j][0];
	if(j) dp[i][j][1] += dp[i - 1][j - 1][1]; 
    }
  }
  while(T--){
    int idx, n, k;
    cin >> idx >> n >> k;
    cout << idx << " " << dp[n][k][0] + dp[n][k][1] << endl;
  }
  return 0;
}
