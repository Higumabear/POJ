/*
 * 2209.cpp
 *
 * Last update: <12/29/2012 05:16:09>
 */

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
#include <numeric>
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;

int main(){
  int n, m;
  cin >> n;
  cin >> m;

  int sum = 0;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    int t = (int)pow((double)a, (double)m);
    if(t > 0) sum += t;
  }
  cout << sum << endl;
  return 0;
}