// Time-stamp: <Mon Sep 12 23:47:43 東京 (標準時) 2016>
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

int dp[50][50];
int main(int argc, char **argv){
  int N;
  scanf("%d\n", &N);
  for(int k = 1; k <= N; k++){
    char s[50], t[50];
    gets(s);
    gets(t);
    
    FILL(dp, 0);
    int L = strlen(s), M = strlen(t);
    sort(s, s + L);
    sort(t, t + M);
    
    for(int i = 0; i < L; i++)
      for(int j = 0; j < M; j++)
	dp[i + 1][j + 1] = max(dp[i][j + 1],
			       max(dp[i + 1][j], 
				 dp[i][j] + (s[i] == t[j])));
    
    printf("Case #%d:  %d\n", k, L + M - 2 * dp[L][M]);
  }
  return 0;
}
