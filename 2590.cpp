// Time-stamp: <Mon Jan 23 22:50:44 東京 (標準時) 2017>
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

ll step[200000];
int main(int argc, char **argv){
  FILL(step, 0LL);
  for(ll i = 1; i < 100000; i++){
    step[2 * i - 1] = i * i;
    step[2 * i] = i * i + i;
  }

  int t;
  cin >> t;
  while(t--){
    ll x, y;
    cin >> x >> y;
    cout << (int)(lower_bound(step, step + 98000, y - x) - step) << endl;
  }
  return 0;
}
