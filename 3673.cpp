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
  string s, t;
  cin >> s >> t;
  int N = s.length();
  int M = t.length();
  int ret = 0;
  for(int i = 0; i < N; i++) for(int j = 0; j < M; j++)
			       ret += (s[i] - '0') * (t[j] - '0');
  cout << ret << endl;
  return 0;
}