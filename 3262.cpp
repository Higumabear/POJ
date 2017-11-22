// Time-stamp: <Mon May 08 21:29:55 東京 (標準時) 2017>
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

struct cow{
  ll T, D;
  bool operator<(const cow &r)const { return r.T * D < T * r.D; }
};

cow c[100002];
ll sum[100002];

int main(int argc, char **argv){
  int N;
  scanf("%d", &N);
  for(int i = 0; i < N; i++)
    scanf("%d %d", &c[i].T, &c[i].D);
  sort(c, c + N);
  sum[0] = 0;
  for(int i = 1; i < N; i++)
    sum[i] = sum[i - 1] + c[i - 1].D;

  ll ans = 0;
  for(int i = 0; i < N; i++)
    ans += (sum[i] * c[i].T * 2LL);
  printf("%lld\n", ans);
  return 0;
}
