// Time-stamp: <Sat May 13 13:30:40 東京 (標準時) 2017>
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

int f[1001];

int main(int argc, char **argv){
  int N, P, C;
  cin >> N >> P >> C;
  for(int i = 0; i < N; i++){
    int idx; cin >> idx;
    f[idx - 1]++;
  }

  int ans = 0;
  for(int l = 0; l < P; l++){
    int r = l;
    int cnt = 0;
    while(cnt + f[r] <= C && r < P - 1)
      cnt += f[r++];
    ans = max(ans, r - l);
  }
  cout << ans << endl;
  return 0;
}
