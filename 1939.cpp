// Time-stamp: <Tue Mar 07 21:49:22 東京 (標準時) 2017>
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

double x[1000000], y[1000000];

int main(int argc, char **argv){
  int N;
  while(scanf("%d", &N) != EOF){
    for(int i = 0; i < N; i++)
      scanf("%lf %lf", x + i, y + i);
    
    printf("%d ", N);
    for(int i = 0; i < N; i++)
      printf("%.6f %.6f ", (x[i] + x[(i + 1) % N]) * 0.5, (y[i] + y[(i + 1) % N]) * 0.5);
    printf("\n");
  }
  return 0;
}
