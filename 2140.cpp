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
  cin >> n;
  int ans = 0;
  for(int i = 1; i * i <= 2 * n; i++){
    if(i % 2 == 1 && n % i == 0) ans++;
    if(i % 2 == 0 && n % i == i / 2) ans++;
  }
  cout << ans << endl;
  return 0;
}