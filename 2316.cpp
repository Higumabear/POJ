/*
 * 2316.cpp
 *
 * Last update: <10/09/2013 22:21:08>
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
  int N;
  string cur, sum(10, '0');
  while(cin >> cur){
    N = cur.size();
    for(int i = 0; i < N; i++)
      sum[i] = ((sum[i] -'0')+ (cur[i] - '0')) % 10 + '0';
  }
  for(int i = 0; i < N; i++) cout << sum[i];
  cout << endl;
  return 0;
}