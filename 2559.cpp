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

int L[100001];
int R[100001];
int h[100001];
int st[100001];

int main(){
  int n;
  while(scanf("%d", &n), n){
    for(int i = 0; i < n; i++)
      scanf("%d", &h[i]);

    int t = 0;
    for(int i = 0; i < n; i++){
      while(t > 0 && h[st[t - 1]] >= h[i]) t--;
      L[i] = t == 0 ? 0 : (st[t - 1] + 1);
      st[t++] = i;
    }
    
    t = 0;
    for(int i = n - 1; i >= 0; i--){
      while(t > 0 && h[st[t - 1]] >= h[i]) t--;
      R[i] = t == 0 ? n : st[t - 1];
      st[t++] = i;
    }
    
    ll ret = 0;
    for(int i = 0; i < n; i++)
      ret = max(ret, (ll)h[i] * (R[i] - L[i]));

    cout << ret << endl;
  }
  return 0;
}
