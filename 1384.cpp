// Time-stamp: <Sat Jan 07 13:59:06 東京 (標準時) 2017>
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

int dp[10002];
int v[501], w[501];
int main(int argc, char **argv){
  int T; cin >> T;
  while(T--){
    int A, B; scanf("%d %d", &A, &B);
    B -= A;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d %d", v + i, w + i);

    FILL(dp, INF);
    dp[0] = 0;
    for(int i = 0; i < B; i++){
      for(int j = 0; j < n; j++){
	int nxt = min(i + w[j], 10001);
	dp[nxt] = min(dp[nxt], dp[i] + v[j]);
      }
    }
    if(dp[B] != INF)
      printf("The minimum amount of money in the piggy-bank is %d.\n", dp[B]);
    else 
      printf("This is impossible.\n");
  }
  return 0;
}
