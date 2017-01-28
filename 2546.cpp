// Time-stamp: <Tue Jan 17 23:10:41 東京 (標準時) 2017>
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
#include <complex>

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

typedef complex<double> pt;

double common_area(pt c1, double r1, pt c2, double r2){
  double d = abs(c1 - c2);
  if(r1 + r2 <= d + EPS) return 0.0;
  if(d <= abs(r1 - r2) + EPS)
    return min(r1, r2) * min(r1, r2) * 3.141592653;
  double rc = (d * d + r1 * r1 - r2 * r2) / (2.0 * d);
  double theta = acos(rc / r1);
  double phi = acos((d - rc) / r2);
  return r1 * r1 * theta + r2 * r2 * phi - d * r1 * sin(theta);
}

int main(int argc, char **argv){
  double x1, y1, r1, x2, y2, r2;
  scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
  printf("%.3lf\n", common_area(pt(x1, y1), r1, pt(x2, y2), r2));
  return 0;
}
