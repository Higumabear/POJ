// Time-stamp: <Wed Nov 30 21:59:49 東京 (標準時) 2016>
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
  int s, d;
  while(cin >> s >> d){
    int ans = -INF;
    for(int S = 0; S < 1 << 12; S++){
      int total = 0;
      for(int r = 4; r < 12; r++){
	int earn = 0;
	for(int i = 0; i < 5; i++){
	  if((S >> (r - i)) & 1) earn += s;
	  else earn -= d;
	}
	if(earn >= 0) goto L1;
      }
      for(int mon = 0; mon < 12; mon++) {
	if(S >> mon & 1) total += s;
	else total -= d;
      }
      ans = max(ans, total);
    L1:;
    }
    if(ans < 0) cout << "Deficit" << endl;
    else cout << ans << endl;
  }
  return 0;
}
