// Time-stamp: <Sat Oct 29 03:07:27 東京 (標準時) 2016>
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
  int N, M, K;
  cin >> N >> M >> K;
  
  int k[2][10];
  FILL(k, 0);

  int ans = 0;
  for(int i = 0; i < K; i++) cin >> k[0][i];
  for(int i = 0; i < K; i++) cin >> k[1][i];
  for(int i = 0; i < K; i++) ans += abs(k[0][i] - k[1][i]);
  cout << ans / 2 << endl;
  return 0;
}