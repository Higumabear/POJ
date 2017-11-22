// Time-stamp: <Wed Aug 02 19:31:11 東京 (標準時) 2017>
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

bool found;

void rec(ll x, int d, ll a){
  if(found) return;
  if(x % a == 0){
    cout << x << endl;
    found = true;
    return;
  }
  if(d > 18) return;
  rec(10 * x + 1, d + 1, a);
  rec(10 * x, d + 1, a);
}

int main(int argc, char **argv){
  ll a;
  while(cin >> a, a){
    found = false;
    rec(1, 1, a);
  }
  return 0;
}
