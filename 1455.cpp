/*
 * 1455.cpp
 *
 * Last update: <06/08/2013 19:18:41>
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
#define ALL(c) (c).begin(), (c).end()

using namespace std;
static const double EPS = 1e-8;
static const int INF = 1 << 29;
typedef long long ll;

int main(){
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    cout << (n / 2) * (n / 2 - 1) / 2 
      + (n - n / 2) * (n - n / 2 - 1) / 2 << endl;
  }
  
  return 0;
}