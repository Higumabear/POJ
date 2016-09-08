// Time-stamp: <Thu Aug 11 00:43:53 東京 (標準時) 2016>
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
  int N, L;
  while(scanf("%d %d", &N, &L) != -1){
    vector<int> p(N), sum(N);
    for(int i = 0; i < N; i++){
      scanf("%d", &p[i]);
      p[i] %= L;
    }
    sum[0] = p[0];
    for(int i = 1; i < N; i++)
      sum[i] = sum[i - 1] + p[i];

    sort(ALL(p));

    int tax = INF, y = -1;
    for(int i = 0; i < L; i++){
      int idx = lower_bound(ALL(p), L - i) - p.begin();
      if(tax > sum[N - 1] + i * N - (N - idx) * L){
	tax = sum[N - 1] + i * N - (N - idx) * L;
	y = i;
      }
    }
    cout << y << endl;
  }
  return 0;
}
