// Time-stamp: <Fri Apr 14 00:21:06 東京 (標準時) 2017>
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
  int n, m;
  while(scanf("%d %d", &n, &m)){
    if(n == -1) break;
    
    int p = 1;
    while(p * (p - 1) / 2 < m) p++;
    int tmp = p * (p - 1) / 2;
    for(int i = 1; i <= n - p; i++)
      printf("%d ", i);
    printf("%d ", n - tmp + m);
    for(int i = n; i >= n - p + 1; i--)
      if(i != n - tmp + m)
	printf("%d ", i);
    puts("");
  }
  
  return 0;
}
