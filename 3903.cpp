// Time-stamp: <Tue Dec 13 23:08:08 東京 (標準時) 2016>
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

int val[100001], dp[100001];
int main(int argc, char **argv){
  int n;
  while(scanf("%d", &n) != EOF){
    FILL(dp, INF);
    for(int i = 0; i < n; i++) scanf("%d", &val[i]);
    for(int i = 0; i < n; i++)
      *lower_bound(dp, dp + n, val[i]) = val[i];
    printf("%d\n", lower_bound(dp, dp + n, INF) - dp);
  }
  return 0;
}
