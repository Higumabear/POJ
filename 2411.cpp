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
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;

int w, h;
ll dp[2][1 << 11];

int main(){
  while(cin >> w >> h, w | h){
    if(w * h % 2 == 1){
      cout << 0 << endl;
      continue;
    }
    memset(dp, 0, sizeof(dp));
    ll *cur = dp[0], *next = dp[1];
    cur[0] = 1;
    for(int i = w - 1; i >= 0; i--){
      for(int j = h - 1; j >= 0; j--){
	for(int used = 0; used < 1 << h; used++){
	  if(used >> j & 1){
	    next[used] = cur[used & ~(1 << j)];
	  }else{
	    ll res = 0;
	    if(j + 1 < h && !(used >> (j + 1) & 1))
	      res += cur[used | 1 << (j + 1)];
	    if(i + 1 < w)
	      res += cur[used | 1 << j];
	    next[used] = res;
	  }
	}
	swap(cur, next);
      }
    }
    cout << cur[0] << endl;
  }
  return 0;
}
