// Time-stamp: <Tue Aug 16 21:22:01 東京 (標準時) 2016>
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

int dp[2][12900];

int main(int argc, char **argv){
  FILL(dp,0);
  int N, M;
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++){
    int w, v;
    scanf("%d %d", &w, &v);
    for(int j = 0; j <= M; j++){
      if(j < w) dp[(i + 1) % 2][j] = dp[i % 2][j];
      else dp[(i + 1) % 2][j] = max(dp[i % 2][j], dp[i % 2][j - w] + v);
    }
  }
  cout << dp[N % 2][M] << endl;
  return 0;
}