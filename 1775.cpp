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

bool ok[1000001];

int main(){
  int f = 1;
  ok[0] = true;
  for(int i = 0; i < 10; i++){
    if(i) f *= i;
    for(int j = 1000000 - f; j >= 0; j--){
      if(ok[j]) ok[j + f] = true;
    }
  }
  ok[0] = false;
  
  int n = 0;
  while(cin >> n, n >= 0) cout << (ok[n] ? "YES" : "NO") << endl;
  return 0;
}