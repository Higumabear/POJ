// Time-stamp: <Sun Feb 12 13:29:32 東京 (標準時) 2017>
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

int a[1001000], b[1001000];
int main(int argc, char **argv){
  int n, m;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", a + i);
  scanf("%d", &m);
  for(int i = 0; i < m; i++) scanf("%d", b + i);
  reverse(b, b + m);
  bool check = false;
  for(int i = 0; i < n; i++){
    int k = upper_bound(b, b + m, 10000 - a[i]) - lower_bound(b, b + m, 10000 - a[i]);
    if(k > 0){
      check = true;
      break;
    }
  }
  printf("%s\n", check ? "YES" : "NO");
  return 0;
}
