// Time-stamp: <Sat Jan 07 16:08:54 東京 (標準時) 2017>
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

vector<ll> pr;
bool prime[200001];
int main(int argc, char **argv){
  ll m, a, b;
  FILL(prime, true);
  prime[0] = prime[1] = false;
  for(int i = 2; i * i <= 200000; i++){
    if(prime[i])
      for(int j = 2 * i; j <= 200000; j += i) prime[j] = false;
  }
  for(int i = 2; i <= 100000; i++) if(prime[i]) pr.push_back(i);
  while(cin >> m >> a >> b){
    if(m == 0 && a == 0 && b == 0) break;

    ll v = 0, s = 0, t = 0;
    for(int i = 0; i < pr.size(); i++){
      if(pr[i] > m) continue;
      for(int j = i; j < pr.size(); j++){
	if(pr[i] * pr[j] > m) break; 
	if(a * pr[j] <= b * pr[i] && 
	   v < pr[i] * pr[j]){
	  v = pr[i] * pr[j];
	  s = pr[i], t = pr[j];
	}
      }
    }
    cout << s << " " << t << endl;
  }
  return 0;
}
