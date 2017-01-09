// Time-stamp: <Tue Dec 13 22:43:09 東京 (標準時) 2016>
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

int rem[1000001];
int test[100];
int main(int argc, char **argv){
  int t;
  scanf("%d", &t);
  while(t--){
    int d, n;
    scanf("%d %d", &d, &n);
    FILL(rem, 0);
    rem[0] = 1;

    int sum = 0, ans = 0, v;
    for(int i = 0; i < n; i++){
      scanf("%d", &v);
      sum = (sum + v) % d;
      ans += rem[sum];
      rem[sum]++;
    }
    printf("%d\n", ans);

    // int tmp = 0;
    // for(int i = 0; i < n; i++){
    //   for(int j = i; j < n; j++){
    // 	int val = 0;
    // 	for(int k = i; k <= j; k++) val += test[k];
    // 	if(val % d == 0) tmp++;
    //   }
    // }
    // dump(tmp);
  }
  return 0;
}
