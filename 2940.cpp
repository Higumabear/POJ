// Time-stamp: <Thu Mar 30 22:21:59 東京 (標準時) 2017>
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

int x[100001];

int main(int argc, char **argv){
  int N;
  while(scanf("%d", &N), N){
    for(int i = 0; i < N; i++)
      scanf("%d", x + i);
  
    int m = 0, p = 0;
    ll ans = 0;
    while(1){
      while(p < N && x[p] <= 0) p++;
      while(m < N && x[m] >= 0) m++;
      if(p >= N && m >= N) break;
    
      int d = min(x[p], -x[m]);
      x[p] -= d;
      x[m] += d;
      ans += (ll)(d * abs(p - m));
    }
    printf("%lld\n", ans);
  }
  return 0;
}
