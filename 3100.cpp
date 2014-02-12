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


int expint(int a, int n){
  int ret = 1;
  for(int i = 0; i < n; i++){
    ret *= a;
  }
  return ret;
}

int main(){
  int B, N;
  while(cin >> B >> N){
    if(B == 0 && N == 0) break;
    double cand = pow(B, 1.0 / N);
    int a = cand;
    int b = a + 1;
    if(abs(expint(a, N) - B) > abs(expint(b, N) - B))
      cout << b << endl;
    else 
      cout << a << endl;
  }
  return 0;
}