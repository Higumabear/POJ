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

int main(){
  int n, k;
  while(cin >> n >> k){
    int res = n;
    while(n / k > 0){
      res += n / k;
      int tmp = n;
      n /= k;
      n += (tmp % k);
    }
    cout << res << endl;
  }
  return 0;
}