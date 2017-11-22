// Time-stamp: <Wed May 10 23:38:47 東京 (標準時) 2017>
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

int T, N, M;
int w[50010], sum[50010];
int dp[50010][4];

int main(int argc, char **argv){
  scanf("%d", &T);
  while(T--){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
      scanf("%d", w + i);
      sum[i] = sum[i - 1] + w[i];
    }
    scanf("%d", &M);
    FILL(dp, 0);
    for(int i = M; i <= N; i++)
      for(int j = 1; j <= 3; j++)
	dp[i][j] = max(dp[i - 1][j], dp[i - M][j - 1] + sum[i] - sum[i - M]);

    printf("%d\n", dp[N][3]);
  }
  return 0;
}
