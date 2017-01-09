// Time-stamp: <Sat Dec 24 16:48:10 東京 (標準時) 2016>
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
  if(idx + 8 < 16) T ^= 1 << (idx + 8);
  if(idx - 8 >= 0) T ^= 1 << (idx - 8);
  if(idx + 12 < 16) T ^= 1 << (idx + 12);
  if(idx - 12 >= 0) T ^= 1 << (idx - 12);
  if(idx % 4 != 0) T ^= 1 << (idx - 1);
  if(idx % 4 != 3) T ^= 1 << (idx + 1);
  if(idx % 4 >= 2) T ^= 1 << (idx - 2);
  if(idx % 4 <= 1) T ^= 1 << (idx + 2);
  if(idx % 4 >= 3) T ^= 1 << (idx - 3);
  if(idx % 4 <= 0) T ^= 1 << (idx + 3);
}
int main(int argc, char **argv){
  int S = 0;
  for(int i = 0; i < 4; i++){
    string s; cin >> s;
    for(int j = 0; j < 4; j++)
      if(s[j] == '+') S |= (1 << (4 * i + j));
  }
  int ans = INF, F;
  for(int M = 0; M < 1 << 16; M++){
    int T = S, cnt = 0;
    if(ans <= __builtin_popcount(M)) continue;
    for(int i = 0; i < 16; i++){
      if(!(M >> i & 1)) continue;
      cnt++;
      flip(T, i);
    }
    if(T == 0 && cnt < ans){
      ans = cnt;
      F = M;
    }
  }
  cout << ans << endl;
  for(int i = 0; i < 16; i++)
    if(F >> i & 1) cout << i / 4 + 1 << " " << i % 4 + 1 << endl;
  return 0;
}
