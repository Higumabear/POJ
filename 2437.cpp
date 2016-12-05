// Time-stamp: <Wed Sep 14 22:59:08 東京 (標準時) 2016>
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
  int N, K;
  cin >> N >> K;
  vector<pair<int, int> > m;
  for(int i = 0; i < N; i++){
    int l, r; cin >> l >> r;
    m.push_back(make_pair(l, r));
  }
  sort(ALL(m));
  
  int idx, cnt = 0, r = 0;
  for(idx = 0; idx < N;){
    r = m[idx].first;
    //dump(r);
    int c = (m[idx].second - m[idx].first + K - 1) / K;
    cnt += c;
    r += c * K;
    idx++;
    while(m[idx].first < r && idx < N){
      c = (m[idx].second - r + K - 1) / K;
      cnt += c;
      r += c * K;
      idx++;
    }
  }
  cout << cnt << endl;
  return 0;
}
