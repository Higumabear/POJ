// Time-stamp: <Sun Aug 07 14:43:57 東京 (標準時) 2016>
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

int gcd(int a, int b){return b == 0 ? a : gcd(b, a % b);};

ll labs(ll a){ return a >= 0LL ? a : -1LL * a;}
int main(int argc, char **argv){
  ll N, D;
  cin >> N >> D;
  
  double diff = 1e100;
  ll A, B;
  for(ll DD = 1; DD <= 32767; DD++){
    if(DD == D) continue;
    ll NN = N * DD * 1.0 / D;
    for(ll T = max(0LL, NN - 2); T <= min(32767LL, NN + 2); T++){
      if(gcd(T, DD) > 1) continue;
      double d = abs(N * 1.0 / D - T * 1.0 / DD);
      if(diff > d){
	diff = d;
	A = T, B = DD;
      }
    }
  }
  cout << A << " " << B << endl;
  return 0;
}
