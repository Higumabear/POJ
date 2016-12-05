// Time-stamp: <Thu Oct 06 22:00:01 東京 (標準時) 2016>
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

int main(int argc, char **argv){
  int n;
  scanf("%d", &n);
  
  vector<ll> A(n), B(n), C(n), D(n);
  for(int i = 0; i < n; i++)
    scanf("%lld %lld %lld %lld", &A[i], &B[i], &C[i], &D[i]);

  vector<ll> AB(n * n), CD(n * n);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
      AB[i * n + j] = A[i] + B[j];
      CD[i * n + j] = C[i] + D[j];
    }
  sort(ALL(CD));
  
  ll ans = 0;
  for(int i = 0; i < n * n; i++)
    ans += (upper_bound(ALL(CD), -AB[i]) - lower_bound(ALL(CD), -AB[i]));
 
  printf("%lld\n", ans);
  return 0;
}
