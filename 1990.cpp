// Time-stamp: <Thu Jul 27 00:25:33 東京 (標準時) 2017>
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

template <class T>
struct BIT{
  int N;
  vector<T> dat;
  T sum(int i){ // return sum [0, i)
    i--;
    T s = 0;
    while(i > 0){
      s += dat[i];
      i -= i & -i;
    }
    return s;
  }
public:
  BIT(int sz) : N(sz) { dat.assign(2 * sz + 2, 0); }
    T sum(int l, int r){ // return sum [l, r)
    return sum(r + 1) - sum(l);
  }
  void add(int i, T x){
    while(i <= N){
      dat[i] += x;
      i += i & -i;
    }
  }
};

int main(int argc, char **argv){
  int N;
  cin >> N;
  vector<pair<int, int> > q(N);

  int f = 0;
  for(int i = 0; i < N; i++){
    cin >> q[i].first >> q[i].second;
    f = max(f, q[i].second);
  }
  sort(ALL(q));
  
  BIT<ll> cnt(f), sum(f);
  ll ans = 0;
  for(int i = 0; i < N; i++){
    ll tmp = 0;
    int cur = q[i].second;
    tmp += (sum.sum(cur, f) - cnt.sum(cur, f) * cur);
    tmp += (cnt.sum(cur) * cur - sum.sum(cur));
    ans += tmp * q[i].first;

    cnt.add(q[i].second, 1);
    sum.add(q[i].second, q[i].second);
  }
  cout << ans << endl;
  return 0;
}
