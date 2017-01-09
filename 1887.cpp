// Time-stamp: <Wed Dec 21 21:36:23 東京 (標準時) 2016>
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

int dp[33000], a[33000];
int main(int argc, char **argv){
  int idx = 0;
  while(1){
    int N = 0;
    int v;
    scanf("%d", &v);
    a[N++] = v;
    if(v == -1) break;
    while(1){
      scanf("%d", &v);
      if(v == -1) break;
      a[N++] = v;
    }
    reverse(a, a + N);
    fill(dp, dp + N, INF);
    for(int i = 0; i < N; i++)
      *lower_bound(dp, dp + N, a[i]) = a[i];
    printf("Test #%d:\n", ++idx);
    printf("  maximum possible interceptions: %d\n\n",
	   lower_bound(dp, dp + N, INF) - dp);
  }
  return 0;
}
