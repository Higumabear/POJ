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
  int n;
  while(cin >> n){
    ll k = 1;
    int ans = 1;
    while(k %= n){
      k = (10 * k + 1) % n;
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
