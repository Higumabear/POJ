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

map<ll, ll> factor(ll a){
  map<ll, ll> pf;
  for(ll i = 2; i * i <= a; i++){
    while(a % i == 0){
      pf[i]++;
      a /= i;
    }
  }
  if(a != 1) pf[a]++;
  return pf;
}

int main(){
  ll n, m;
  while(cin >> n >> m){
    map<ll, ll> pf = factor(m);

    bool check = true;
    if(m != 0){
      map<ll, ll>::iterator it = pf.begin();
      for(; it != pf.end(); it++){
	ll base = it->first, x = base;
	int num = 0;
	while(x <= m){
	  num += (n / x);
	  x *= base;
	}

	if(num < it->second)
	  check = false;
      }
    }else check = false;
    
    if(check)
      cout << m << " divides " << n << "!" << endl;
    else
      cout << m << " does not divide " << n << "!" << endl;
  }
  return 0;
}
