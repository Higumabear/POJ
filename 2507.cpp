// Time-stamp: <Tue Feb 28 22:17:51 東京 (標準時) 2017>
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
#define EPS 1e-9
#define ALL(c) (c).begin(), (c).end()
#define CNT(c,x) count(ALL(c),x)
#define dump(x)  cerr << #x << " = " << (x) << endl;
template<typename A, size_t N, typename T>
void FILL(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

using namespace std;

int main(int argc, char **argv){
  double x, y, c;
  while(cin >> x >> y >> c){
    double ub = min(x, y);
    double lb = 0;
    for(int i = 0; i < 100; i++){
      double mid = (ub + lb) * 0.5;
      double A = sqrt(y * y - mid * mid);
      double B = sqrt(x * x - mid * mid);
      double C = A * B / (A + B);
      if(c > C) ub = mid;
      else lb = mid;
    }
    printf("%.3lf\n", ub);
  }
  return 0;
}
