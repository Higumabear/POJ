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

int X, Y;
int n, m, X1, Y1, X2, Y2;
int u[5000], l[5000];

bool C(int idx){
  int vX = l[idx] - u[idx], vY = Y2 - Y1;
  int wX = X - u[idx], wY = Y - Y1;
  return vX * wY - vY * wX > 0;
}

int main(){
  while(scanf("%d", &n), n){
    scanf("%d %d %d %d %d", &m, &X1, &Y1, &X2, &Y2);
    u[0] = l[0] = 0;
    for(int i = 1; i <= n; i++)
      scanf("%d %d", u + i, l + i);

    map<int, int> ans;
    for(int i = 0; i < m; i++){
      scanf("%d %d", &X, &Y);

      int lb = 0, ub = n + 1;
      while(1 < ub - lb){
	int mid = (lb + ub) / 2;
	(C(mid) ?  lb : ub) = mid;
      }
      ans[lb]++;
    }
    for(int i = 0; i <= n; i++)
      printf("%d: %d\n", i, ans[i]);
    puts("");
  }
  return 0;
}
