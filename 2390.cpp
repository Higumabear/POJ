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
  double R;
  int M,Y;
  cin >> R >> M >> Y;
  double interest = 1.0 + R / 100.0;
  interest = pow(interest, (double)Y);
  cout << (int)(interest * M) << endl;
  return 0;
}