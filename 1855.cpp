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

inline ll gcd(ll a, ll b){ return b == 0 ? a : gcd(b, a % b); }
inline ll lcm(ll a, ll b){ return a / gcd(a, b) * b; }

int e[51];

int main(int argc, char **argv){
  int N, M;
  while(cin >> N >> M, N + M){
    for(int i = 0; i < N; i++) cin >> e[i];
    sort(e, e + N);
    int v[4];
    while(M--){
      ll T; cin >> T;
      ll miv = 0, mav = LLINF;
      ll S = (1LL << 4) - 1;
      for(int a = 0; a < N; a++){
	for(int b = a + 1; b < N; b++){
	  for(int c = b + 1; c < N; c++){
	    for(int d = c + 1; d < N; d++){
	      v[0] = e[a], v[1] = e[b], v[2] = e[c], v[3] = e[d];
	      ll g = v[0];
	      for(int j = 0; j < 4; j++)
		g = lcm(g, v[j]);
	      
	      miv = max(miv, T / g * g);
	      mav = min(mav, (T + g - 1) / g * g);
	    }
	  }
	}
      }
      // while(S < 1LL << N){
      // 	int idx = 0;
      // 	for(int j = 0; j < N; j++)
      // 	  if(S >> j & 1) v[idx++] = d[j];

      // 	ll g = v[0];
      // 	for(int j = 0; j < 4; j++)
      // 	  g = lcm(g, v[j]);

      // 	miv = max(miv, T / g * g);
      // 	mav = min(mav, (T + g - 1) / g * g);

      // 	ll x = S & -S, y = S + x;
      // 	S = ((S & ~y) / x >> 1) | y;
      // }
      cout << miv << " " << mav << endl;
    }
      
  }
  return 0;
}
