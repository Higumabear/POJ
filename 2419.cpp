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
  int T, P;
  cin >> P >> T;
  vector<set<int> > info(P);
  while(cin >> P >> T) info[P - 1].insert(T);

  sort(info.begin(), info.end());
  info.erase(unique(info.begin(), info.end()), info.end());
  cout << info.size() << endl;
  return 0;
}