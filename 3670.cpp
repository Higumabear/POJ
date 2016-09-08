// Time-stamp: <Wed Aug 17 21:38:01 東京 (標準時) 2016>
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

int dp[30010];
int main(int argc, char **argv){
  int N; scanf("%d", &N);
  vector<int> a(N);
  for(int i = 0; i < N; i++) 
    scanf("%d", &a[i]);

  int ans = INF;
  for(int k = 0; k <= 1; k++){
    FILL(dp, INF);
    for(int i = 0; i < N; i++) 
      *upper_bound(dp, dp + N, a[i]) = a[i];

    ans = min(ans, N - (int)(lower_bound(dp, dp + N, INF) - dp));
    reverse(ALL(a));
  }
  printf("%d\n", ans);
  return 0;
}