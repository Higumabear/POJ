// Time-stamp: <Fri Dec 02 22:35:17 東京 (標準時) 2016>
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

int l(int n, int m){
  return n * n * n + m * (m + 1) * (m + 2) / 6;
}
int main(int argc, char **argv){
  int f;
  while(cin >> f, f){
    int ans = 0;
    for(int i = 0; i <= 55; i++)
      for(int j = 0; j <= 100; j++)
	if(l(i, j) <= f) ans = max(ans, l(i, j));
    cout << ans << endl;
  }
  return 0;
}
