// Time-stamp: <Thu Oct 27 23:59:48 東京 (標準時) 2016>
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
  double x1, y1, x2, y2, x3, y3;
  while(scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3) != -1){
    double t = 0.5 * ((x3-x2)*(x3-x1)-(y1-y3)*(y3-y2)) / ((y2-y1)*(x3-x1)-(y1-y3)*(x1-x2));
    double x0=(x1+x2)/2+t*(y2-y1);
    double y0=(y1+y2)/2-t*(x2-x1);
    double R = sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
    printf("%.2f\n", 2.0 * R * 3.141592653589793);
  }
  return 0;
}