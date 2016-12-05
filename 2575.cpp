// Time-stamp: <Wed Sep 14 00:39:57 東京 (標準時) 2016>
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

int d[4000];
int main(int argc, char **argv){
  int n;
  while(scanf("%d", &n) != EOF){
    fill(d + 1, d + 4000, 1);
    int a, b;
    scanf("%d", &a);
    for(int i = 1; i < n; i++){
      scanf("%d", &b);
      int diff = abs(b - a);
      if(diff < 4000) d[diff]--;
      swap(a, b);
    }
    bool ok = true;
    for(int i = 1; i <= n - 1; i++)
      ok &= (d[i] == 0);
    printf("%s\n", ok ? "Jolly" : "Not jolly");
  }
  return 0;
}
