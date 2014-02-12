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
  vector<int> milk;
  int n; cin >> n;

  int t;
  for(int i = 0; i < n; i++){
    cin >> t;
    milk.push_back(t);
  }
  
  sort(milk.begin(), milk.end());
  cout << milk[n / 2] << endl;
  return 0;
}