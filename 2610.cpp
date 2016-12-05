// Time-stamp: <Thu Nov 17 01:00:48 東京 (標準時) 2016>
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

//double hy[1001], hx[1001];
int main(int argc, char **argv){
  double dy, dx, gy, gx;
  cin >> gx >> gy >> dx >> dy;
  double hy, hx;
  while(cin >> hx >> hy){
    double t = sqrt((hy - gy) * (hy - gy) + (hx - gx) * (hx - gx));
    double T = 0.5 * sqrt((hy - dy) * (hy - dy) + (hx - dx) * (hx - dx));
    if(t < T){
      printf("The gopher can escape through the hole at (%.3f,%.3f).\n",
	     hx, hy);
      return 0;
    }
  }
  printf("The gopher cannot escape.\n");
  return 0;
}