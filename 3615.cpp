// Time-stamp: <Fri Aug 19 01:35:04 東京 (標準時) 2016>
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

int d[300][300];
int main(int argc, char **argv){
  int N, M, T;
  scanf("%d%d%d", &N, &M, &T);
  FILL(d, INF);
  for(int i = 0; i < M; i++){
    int s,t, v;
    scanf("%d%d%d", &s, &t, &v);
    d[s - 1][t - 1] = v;
  }
  for(int k = 0; k < N; k++)
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
	d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
  for(int i = 0; i < T; i++){
    int s,t;
    scanf("%d%d", &s, &t);
    printf("%d\n", ((d[s - 1][t - 1] == INF) ? -1 : d[s - 1][t - 1]));
  }
  return 0;
}
