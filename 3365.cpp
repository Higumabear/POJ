// Time-stamp: <Fri Mar 03 22:44:34 東京 (標準時) 2017>
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
  int w, h;
  double pi = acos(-1);
  while(cin >> w >> h, w + h){
    double X = min((double)w, h * 1.0 / (1.0 + pi));
    double V = w * pi * 0.25 * pow(X, 2.0);
    X = min(w / pi, 2.0 * h / 3.0);
    double W = pi * 0.25 * pow(X, 2.0) * (h - X);
    //cout << V << " " << W << endl;
    printf("%.3f\n", max(V, W));
  }
  return 0;
}
