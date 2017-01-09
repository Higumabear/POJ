// Time-stamp: <Mon Dec 19 23:22:02 東京 (標準時) 2016>
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

class RMQ{
  int N;
  vector<ll> min_dat, max_dat;

public:
  RMQ(int n) : N(1) {
    while(N < n) N *= 2;
    min_dat.assign(2 * N - 1, -1 + (1LL << 31));
    max_dat.assign(2 * N - 1, 1 - (1LL << 31));
  }
  RMQ(vector<int> &arr) : N(1) {
    while(N < arr.size()) N *= 2;
    min_dat.assign(2 * N - 1, -1 + (1LL << 31));
    max_dat.assign(2 * N - 1, 1 - (1LL << 31));
    copy(arr.begin(), arr.end(), min_dat.begin() + N - 1);
    copy(arr.begin(), arr.end(), max_dat.begin() + N - 1);
    for(int i = N - 2; i >= 0; i--){
      min_dat[i] = min(min_dat[2 * i + 1], min_dat[2 * i + 2]);
      max_dat[i] = max(max_dat[2 * i + 1], max_dat[2 * i + 2]);
    }
  }
  void update(int idx, int val){
    idx += N - 1;
    min_dat[idx] = val;
    max_dat[idx] = val;
    while(idx > 0){
      idx = (idx - 1) / 2;
      min_dat[idx] = min(min_dat[2 * idx + 1], min_dat[2 * idx + 2]);
      max_dat[idx] = max(max_dat[2 * idx + 1], max_dat[2 * idx + 2]);
    }
  }
  int min_query(int a, int b){ return min_query(a, b, 0, 0, N); }
  int min_query(int a, int b, int k, int l, int r){
    if(r <= a || b <= l) return -1LL + (1LL << 31);
    if(a <= l && r <= b) return min_dat[k];
    return min(min_query(a, b, 2 * k + 1, l, (l + r) / 2),
	       min_query(a, b, 2 * k + 2, (l + r) / 2, r));
  }
  int max_query(int a, int b){ return max_query(a, b, 0, 0, N); }
  int max_query(int a, int b, int k, int l, int r){
    if(r <= a || b <= l) return 1LL - (1L << 31);
    if(a <= l && r <= b) return max_dat[k];
    return max(max_query(a, b, 2 * k + 1, l, (l + r) / 2),
	       max_query(a, b, 2 * k + 2, (l + r) / 2, r));
  }
};

int main(int argc, char **argv){
  int n, q;
  scanf("%d %d", &n, &q);
  vector<int> data(n);
  for(int i = 0; i < n; i++) scanf("%d", &data[i]);
  RMQ rmq(data);
  for(int i = 0; i < q; i++){
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%d\n", rmq.max_query(l - 1, r) - rmq.min_query(l - 1, r));
  }
  return 0;
}
