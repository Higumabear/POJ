// Time-stamp: <Sat Mar 18 15:21:44 東京 (標準時) 2017>
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

int ye[500][500];
int bl[500][500];
int dp[501][501];

int rec(int y, int x){
  if(y <= 0 || x <= 0) return 0;
  if(dp[y][x] != -1) return dp[y][x];
  
  int bottom = 0, right = 0;
  int ret = 0;
  for(int i = 0; i < x; i++) bottom += ye[y - 1][i];
  for(int i = 0; i < y; i++) right += bl[i][x - 1];
  ret = max(bottom + rec(y - 1, x), right + rec(y, x - 1));
  return dp[y][x] = ret;
}

int main(int argc, char **argv){
  int N, M;
  while(scanf("%d %d", &N, &M), N){
    for(int i = 0; i < N; i++)
      for(int j = 0; j < M; j++)
	scanf("%d", &ye[i][j]);
    for(int i = 0; i < N; i++)
      for(int j = 0; j < M; j++)
	scanf("%d", &bl[i][j]);

    FILL(dp, -1);
    printf("%d\n", rec(N, M));
  }
  return 0;
}
