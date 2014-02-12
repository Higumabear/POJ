
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#define ALL(c) (c).begin(), (c).end()

using namespace std;
static const double EPS = 1e-8;
static const int INF = 1 << 29;
typedef long long ll;

bool used[10000];

int main(){
  int N, K;
  scanf("%d", &N);
  scanf("%d", &K);

  int a;
  int cnt = 0;
  int ans = 0;
  for(int i = 0; i < N; i++){
    scanf("%d", &a);
    a--;
    if(!used[a]){
      used[a] = true;
      cnt++;
      if(cnt == K){
	memset(used, false, sizeof(used));
	cnt = 0;
	ans++;
      }
    }
  }
  printf("%d\n", ans + 1);
  return 0;
}
