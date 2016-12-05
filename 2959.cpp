// Time-stamp: <Wed Sep 14 22:17:48 東京 (標準時) 2016>
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
#define EPS 1e-10
#define ALL(c) (c).begin(), (c).end()
#define CNT(c,x) count(ALL(c),x)
#define dump(x)  cerr << #x << " = " << (x) << endl;
template<typename A, size_t N, typename T>
void FILL(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

using namespace std;

int main(int argc, char **argv){
  int N; cin >> N;
  while(N--){
    double s, D, d;
    cin >> D >> d >> s;
    double ub = 1e10, lb = 0;
    for(int i = 0; i < 100; i++){
      double mid = (ub + lb) / 2.0;
      double dist = (D - d) * sin(3.14159265359 / mid);
      if(dist + EPS < d + s) ub = mid;
      else lb = mid;
    }
    cout << floor(ub) << endl;
  }
  return 0;
}
