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
  int n; cin >> n;
  for(int i = 1; i <= n; i++){
    int k; cin >> k;
    ll sum = 0;
    for(int j = 1; j <= k; j++){
      sum += j * (j + 1) * (j + 2) / 2;
    }
    cout << i << " " << k << " " << sum << endl;
  }
  return 0;
}