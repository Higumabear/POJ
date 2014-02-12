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
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;

ll a[250000];

int main(){
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
  sort(a, a + n);
  double ans;
  if(n % 2 == 1) ans = a[n / 2];
  else ans = (a[n / 2 - 1] + a[n / 2]) / 2.0;
  printf("%.1f\n", ans);
  return 0;
}