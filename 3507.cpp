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
#include <numeric>
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;

int main(){
  int a[6];
  while(cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5]){
    if(accumulate(a, a + 6, 0) == 0) break;
    sort(a, a + 6);
    cout << (double)(a[1] + a[2] + a[3] + a[4]) / 4 << endl;
  }
  return 0;
}