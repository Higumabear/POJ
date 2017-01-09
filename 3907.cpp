// Time-stamp: <Tue Dec 13 23:40:24 東京 (標準時) 2016>
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

double x[1000001], y[1000001];
int main(int argc, char **argv){
  int n;
  while(scanf("%d", &n), n){
    double S = 0.0;
    for(int i = 0; i < n; i++) scanf("%lf %lf", &x[i], &y[i]);
    for(int i = 0; i < n; i++)
      S += (x[i] * y[(i + 1) % n] - y[i] * x[(i + 1) % n]);
    S = 0.5 * fabs(S);
    printf("%d\n", (int)(S + 0.5));
  }
  return 0;
}
