// Time-stamp: <Mon Mar 13 23:14:29 東京 (標準時) 2017>
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

ll mpow(ll a, ll p, ll MOD){
  ll ret = 1;
  while(p > 0){
    if(p & 1) ret = (ret * a) % MOD;
    a = a * a % MOD;
    p >>= 1;
  }
  return ret;
}

ll modpow(ll x, ll y, ll m) {
    if (y == 0) return 1;
    ll res = modpow(x, y / 2, m);
    return res * res % m * (y & 1 ? x : 1) % m;
}

bool prime(ll p){
  for(ll i = 2; i * i <= p; i++)
    if(p % i == 0) return false;
  return true;
}

int main(int argc, char **argv){
  ll p, a;
  while(cin >> p >> a, p + a){
    if(prime(p)) cout << "no" << endl;
    else
      cout << (mpow(a, p, p) == a ? "yes" : "no") << endl;
  }
  return 0;
}
