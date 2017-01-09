// Time-stamp: <Fri Dec 23 00:00:30 東京 (標準時) 2016>
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

//int memo[1 << 17];
void flip(int &T, int idx){
  T ^= 1 << idx;
  if(idx + 4 < 16) T ^= 1 << (idx + 4);
  if(idx - 4 >= 0) T ^= 1 << (idx - 4);
  if(idx % 4 != 0) T ^= 1 << (idx - 1);
  if(idx % 4 != 3) T ^= 1 << (idx + 1);
}
int main(int argc, char **argv){
  int S = 0;
  for(int i = 0; i < 4; i++){
    string s; cin >> s;
    for(int j = 0; j < 4; j++)
      if(s[j] == 'w') S |= (1 << (4 * i + j));
  }
  int ans = INF;
  for(int M = 0; M < 1 << 16; M++){
    int T = S, cnt = 0;
    for(int i = 0; i < 16; i++){
      if(!(M >> i & 1)) continue;
      cnt++;
      flip(T, i);
    }
    if(T == 0 || (1 << 16) - 1 == T) ans = min(ans, cnt);
  }
  if(ans == INF) cout << "Impossible" << endl;
  else cout << ans << endl;
  return 0;
}
