// Time-stamp: <Mon Mar 20 16:51:23 東京 (標準時) 2017>
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

ll a[10], b[10];

int main(int argc, char **argv){
  int n1, n2, n;
  while(scanf("%d %d %d", &n1, &n2, &n), n1 + n2 + n){
    FILL(a, INF);
    FILL(b, 0);

    ll sum = 0;
    for(int i = 0; i < n; i++){
      ll v; scanf("%lld", &v);
      sum += v;
      
      int j = n2;
      while(j - 1 >= 0 && v <= a[j - 1]) j--;
      for(int k = n2 - 1; k - 1 >= j; k--) a[k] = a[k - 1];
      if(j != n2) a[j] = v;

      j = n1;
      while(j - 1 >= 0 && v >= b[j - 1]) j--;
      for(int k = n1 - 1; k - 1 >= j; k--) b[k] = b[k - 1];
      if(j != n1) b[j] = v;      
    }

    ll s1 = 0, s2 = 0;
    // for(int i = 0; i < 10; i++)
    //   printf("%d ", a[i]);
    // printf("\n");
    // for(int i = 0; i < 10; i++)
    //   printf("%d ", b[i]);
    // printf("\n");
    for(int i = 0; i < n2; i++) s2 += a[i];
    for(int i = 0; i < n1; i++) s1 += b[i];
    //   printf("%d ", b[i]);
    // printf("\n");

    // ll s2 = accumulate(a, a + n2, 0);
    // ll s1 = accumulate(b, b + n1, 0);
    printf("%.6f\n", (double)(sum - s1 - s2) / (n - n1 - n2));
  }
  return 0;
}
