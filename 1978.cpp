/*
 * 1978.cpp
 *
 * Last update: <12/26/2012 02:32:19>
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
  int n, r;
  while(cin >> n >> r){
    if(n == 0 && r == 0) break;
    string s;
    for(int i = 0; i < n; i++) s += (char)(n - i);

    for(int i = 0; i < r; i++){
      int p, c;
      cin >> p >> c;
      s = s.substr(p - 1, c) + s.substr(0, p - 1) + s.substr(c + p - 1);
    }
    cout << (int)s[0] << endl;
  }
  return 0;
}