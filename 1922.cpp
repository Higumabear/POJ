// Time-stamp: <Wed Nov 19 00:09:32 東京 (標準時) 2014>
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

using namespace std;

int main(int argc, char **argv){
  int N;
  while(scanf("%d", &N) && N > 0){
    int ans = INF;
    for(int i = 0; i < N; i++){
      int V, T;
      scanf("%d %d", &V, &T);
      if(T >= 0)
	ans = min(ans, (int)(ceil(4500.0 / (V * 1000.0 / 3600.0) + T) + EPS));
    }    
    printf("%d\n", ans);
  }
  return 0;
}