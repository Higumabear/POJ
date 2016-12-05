// Time-stamp: <Sun Nov 13 20:20:28 東京 (標準時) 2016>
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


map<ll, int> pf(ll n){
  map<ll, int> p;
  for(ll i = 2; i * i <= n; i++){
    while(n % i == 0){
      p[i]++;
      n /= i;
    }
  }
  if(n != 1) p[n]++;
  return p;
}
int main(int argc, char **argv){
  ll n;
  while(cin >> n, n){
    map<ll, int> pr = pf(n < 0 ? -n : n);
    for(int p = 32; p >= 1; p--){
      bool check = true;
      map<ll, int>::iterator it = pr.begin();
      for(; it != pr.end(); it++){
	ll power = it->second;
	if(power % p != 0 || (n < 0 && p % 2 == 0)) check = false;
      }
      if(check){
	cout << p << endl;
	break;
      }
    }
  }
  return 0;
}
