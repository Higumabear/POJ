// Time-stamp: <Sun Aug 07 19:09:04 東京 (標準時) 2016>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <iomanip>
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

int match[101];
int win[101];
int main(int argc, char **argv){
  int N, K;
  while(scanf("%d", &N), N){
    scanf("%d", &K);
    FILL(match, 0);
    FILL(win, 0);
    for(int i = 0; i < K * N * (N - 1) / 2; i++){
      int s, t;
      char a[10], b[10];
      scanf("%d %s %d %s", &s, a, &t, b);
      s--, t--;
      if(a[0] == b[0]) continue;
      match[s]++, match[t]++;
      if(a[0] == 'r' && b[0] == 's')	win[s]++;
      if(a[0] == 'r' && b[0] == 'p')	win[t]++;
      if(a[0] == 's' && b[0] == 'r')	win[t]++;
      if(a[0] == 's' && b[0] == 'p')	win[s]++;
      if(a[0] == 'p' && b[0] == 'r')	win[s]++;
      if(a[0] == 'p' && b[0] == 's')	win[t]++;
    }
    for(int i = 0; i < N; i++){
      if(match[i] == 0) printf("-\n");
      else{
	printf("%.3f\n", win[i] * 1.0 / match[i]);
      }
    }
    printf("\n");
  }
  return 0;
}
