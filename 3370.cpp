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

int c, n;
int a[100010], rem[100010];

int main(){
  while(scanf("%d %d\n", &c, &n), c + n){
    FILL(rem, -INF);
    rem[0] = -1;
    int sum = 0;
    int l = 0, r = -1;
    for(int i = 0; i < n; i++){
      scanf("%d", a + i);
      sum = a[i] + sum;
      sum %= c;
      if(rem[sum] != -INF){
	l = rem[sum] + 1, r = i;
	break;
      }
      rem[sum] = i;
    }
    for(int i = r + 1; i < n; i++) scanf("%d", a + i);
    for(int i = l; i <= r; i++)
      printf("%d%c", i + 1, i == r ? '\n' : ' ');

  }
  return 0;
}
