//
// Time-stamp: <Thu Mar 13 18:01:02 “Œ‹ž (•W€Žž) 2014>
//
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
using namespace std;
static const double EPS = 1e-8;
static const int INF = 1 << 29;
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;

int main(){
  int T; cin >> T;
  for(int t = 1; t <= T; t++){
    int S, n; cin >> S >> n;
    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(ALL(b), greater<int>());
    int sum = 0, idx;
    for(idx = 0; idx < n && sum < S; sum += b[idx++]);
    cout << "Scenario #" << t << ":" << endl;
    if(sum >= S) cout << idx << endl << endl;
    else cout << "impossible" << endl << endl;
  }
  return 0;
}
