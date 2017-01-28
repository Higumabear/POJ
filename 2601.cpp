// Time-stamp: <Mon Jan 16 22:07:12 東京 (標準時) 2017>
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

int n;
double b, a[3010];
double c[3010];
int main(int argc, char **argv){
  scanf("%d", &n);
  scanf("%lf", &a[0]);
  scanf("%lf", &b);
  for(int i = 1; i <= n; i++)
    scanf("%lf", c + i);
  
  double ub = 1001, lb = -1001;
  for(int i = 0; i < 100; i++){
   a[1] = (ub + lb) / 2;
   for(int i = 2; i <= n + 1; i++)
     a[i] = 2.0 * a[i - 1] - a[i - 2] + 2.0 * c[i - 1];
   if(b > a[n + 1]) lb = a[1];
   else ub = a[1];
  }
  printf("%.2lf\n", a[1]);
  return 0;
}
