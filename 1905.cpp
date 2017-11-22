// Time-stamp: <Fri Mar 17 00:18:04 東京 (標準時) 2017>
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
  double l, n, c;
  while(cin >> l >> n >> c){
    if(l < 0 && n < 0 && c < 0) break;
    
    double ub = acos(( double)-1), lb = 0;
    for(int i = 0; i < 10000; i++){
      double mid = (ub + lb) * 0.5;
      double x = sin(0.5 * mid) / mid;
      double y = 0.5 / (1.0 + n * c);
      if(x > y) lb = mid;
      else ub = mid;
    }
    cout.precision(3);
    cout.setf(ios::fixed);
    cout << ((1.0 - cos(0.5 * ub)) * l * (1.0 + n * c) / ub) << endl;
  }
  return 0;
}
