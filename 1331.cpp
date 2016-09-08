// Time-stamp: <Sun Aug 07 01:08:14 東京 (標準時) 2016>
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

ll c(ll a, int b){
  ll base = 1;
  ll ret = 0;
  while(a){
    if(a % 10 >= b) return -1;
    ret = ret + base * (a % 10);
    base *= b;
    a /= 10;
  }
  return ret;
}
int main(int argc, char **argv){
  int N; cin >> N;
  while(N--){
    ll x, y, z;
    cin >> x >> y >> z;
    for(int base = 2; base <= 100; base++){
      if(c(x, base) != -1 && c(y, base) != -1 && c(z, base) != -1 && 
	 c(x, base) * c(y, base) == c(z, base)){
	cout << base << endl;
	goto L1;
      }
    }
    cout << 0 << endl;
  L1:;
  }
  return 0;
}
