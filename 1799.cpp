/*
 * 1799.cpp
 *
 * Last update: <10/09/2013 23:36:34>
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
const double PI = 3.141592653;

int main(){
  int N;
  cin >> N;
  for(int i= 1; i <= N; i++){
    double R; int n;
    cin >> R >> n;
    double t = PI / n;
    cout << "Scenario #" << i << ":" << endl;
    printf("%.3lf\n\n", R * sin(t) / (1 + sin(t)));
  }
  return 0;
}
