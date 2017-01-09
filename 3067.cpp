// Time-stamp: <Fri Jan 06 00:14:50 東京 (標準時) 2017>
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
public:
  BIT(int sz) : N(sz) { dat.assign(2 * sz + 2, 0); }
  
  T sum(int i){ // return sum [0, i)
    i--;
    T s = 0;
    while(i > 0){
      s += dat[i];
      i -= i & -i;
    }
    return s;
  }
  void add(int i, T x){
    while(i <= N){
      dat[i] += x;
      i += i & -i;
    }
  }
};

int main(int argc, char **argv){
  int T;
  scanf("%d", &T);
  for(int t = 1; t <= T; t++){
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    
    vector<pair<int, int> > p(K);
    for(int i = 0; i < K; i++)
      scanf("%d %d", &p[i].first, &p[i].second);
    
    for(int i = 0; i < K; i++) swap(p[i].first, p[i].second);
    stable_sort(ALL(p));
    for(int i = 0; i < K; i++) swap(p[i].first, p[i].second);
    stable_sort(ALL(p));

    BIT<ll> bit(M);

    ll ans = 0;
    for(int i = 0; i < K; i++){
      // for(int j = p[i].second + 1; j < M; j++) 
      // 	ans += a[j];
      // a[p[i].second]++;
      ans += bit.sum(M + 1) - bit.sum(p[i].second + 1);
      bit.add(p[i].second, 1);
    }
    printf("Test case %d: %lld\n", t, ans);
  }
  return 0;
}
