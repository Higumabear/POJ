// Time-stamp: <Fri May 20 00:36:48 東京 (標準時) 2016>
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

using namespace std;

int main(int argc, char **argv){
  ll a1, a2, a3, a4, a5;
  cin >> a1 >> a2 >> a3 >> a4 >> a5;

  int cnt = 0;
  map<ll, int> p;
  for(ll x4 = -50; x4 <= 50; x4++){
    for(ll x5 = -50; x5 <= 50; x5++){
      if(x4 * x5 == 0) continue;
      p[a4 * x4 * x4 * x4 +
	a5 * x5 * x5 * x5]++;
    }
  }
  for(ll x1 = -50; x1 <= 50; x1++){
    for(ll x2 = -50; x2 <= 50; x2++){
      for(ll x3 = -50; x3 <= 50; x3++){
	if(x1 * x2 * x3 == 0) continue;
	ll r = a1 * x1 * x1 * x1 + 
	  a2 * x2 * x2 * x2 +
	  a3 * x3 * x3 * x3;
	if(p.count(-r)) cnt += p[-r];
      }      
    }
  }
  cout << cnt << endl;
  return 0;
}