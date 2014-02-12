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
  for(int i = 0; i < n; i++){
    int t;
    cin >> t;
    vector<int> shop(t);

    int minval = 114514810;
    for(int j = 0; j < t; j++) cin >> shop[j];
    sort(shop.begin(), shop.end());
    for(int j = shop[0]; j <= shop[t - 1]; j++){
      int sum = (2 * abs(j - shop[0]) + 2 * (abs(j - shop[t - 1])));
      minval = min(minval, sum);
    }
    cout << minval << endl;
  }
  return 0;
}