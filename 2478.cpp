// Time-stamp: <Sun Feb 05 00:51:32 東京 (標準時) 2017>
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

const ll N = 1000100;
ll eulerPhi(ll n) {
  static ll lookup = 0, p[N], f[N];
  if (!lookup) {
    for(ll i = 0; i < N; i++) p[i] = 1, f[i] = i;
    for (ll i = 2; i < N; ++i) {
      if (p[i]) {
        f[i] -= f[i] / i;
        for (ll j = i+i; j < N; j+=i)
          p[j] = 0, f[j] -= f[j] / i;
      }
    }
    lookup = 1;
  }
  return f[n];
}

long long far[1000100];
int main(int argc, char **argv){
  far[1] = 0;
  for(int i = 2; i <= 1000010; i++)
    far[i] = far[i - 1] + eulerPhi(i);
  int x;
  while(cin >> x, x) cout << far[x] << endl;
  return 0;
}
