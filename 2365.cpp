// Time-stamp: <Sun Sep 11 02:13:43 東京 (標準時) 2016>
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
  int N;
  double R;
  scanf("%d %lf", &N, &R);
  vector<double> x(N), y(N);
  for(int i = 0; i < N; i++) scanf("%lf %lf", &x[i], &y[i]);

  double ans = 2.0 * R * 3.1415926535897932;
  for(int i = 0; i < N; i++) 
    ans += sqrt(pow(x[i] - x[(i + 1) % N], 2) 
		+ pow(y[i] - y[(i + 1) % N], 2));
  printf("%.2f\n", ans);
  return 0;
}
