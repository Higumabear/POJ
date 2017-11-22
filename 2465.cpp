// Time-stamp: <Fri Aug 25 21:39:10 東京 (標準時) 2017>
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
#define INF 1LL << 29
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
  int L, a, b;
  cin >> L;
  
  vector<int> p, v;
  p.push_back(0);
  v.push_back(INF);
  while(cin >> a >> b){
    p.push_back(a);
    v.push_back(b);
  }
  p.push_back(L);
  v.push_back(INF);


  ll dp[110][210];
  FILL(dp, INF);
  dp[0][100] = 0;
  for(ll i = 0; i < p.size(); i++){
    for(ll j = 0; j <= 200; j++){
      //if(dp[i][j] >= INF) continue;
      for(ll k = 0; j + k <= 200; k++){
	ll rem = j - p[i + 1] + p[i] + k;
	if(rem >= 0 && rem <= 200)
	  dp[i + 1][rem] = min(dp[i + 1][rem], dp[i][j] + k * v[i]);
      }
    }
  }

  ll ans = INF;
  for(int i = 100; i <= 200; i++)
    ans = min(dp[p.size() - 1][i], ans);

  if(ans >= INF) cout << "Impossible" << endl;
  else cout << ans << endl;
  return 0;
}

