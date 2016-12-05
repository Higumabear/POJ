// Time-stamp: <Wed Nov 30 23:51:49 東京 (標準時) 2016>
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

double dp[101][10];
int main(int argc, char **argv){
  int k, n;
  while(scanf("%d %d", &k, &n) != EOF){
    FILL(dp, 0);
    for(int i = 0; i < 10; i++) dp[1][i] = 100;
    for(int i = 1; i < n; i++){
      for(int j = 0; j <= k; j++){
	if(j - 1 >= 0) dp[i + 1][j] += dp[i][j - 1] / (k + 1);
	if(j + 1 <= k) dp[i + 1][j] += dp[i][j + 1] / (k + 1);
	dp[i + 1][j] += dp[i][j] / (k + 1);
      }
    }
    double ans = 0;
    for(int i = 0; i <= k; i++) ans += dp[n][i];
    printf("%.5f\n", ans / (k + 1));
  }
  return 0;
}
