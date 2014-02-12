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

bool sieve[1000001];

int main(){
  int n;
  memset(sieve, true, sizeof(sieve));
  sieve[0] = sieve[1] = false;
  for(int i = 2; i <= 1000000; i++) if(sieve[i])
    for(int j = 2 * i; j <= 1000000; j += i)
      sieve[j] = false;
  while(cin >> n, n){
    for(int i = 3; i <= n - i; i += 2)
      if(sieve[i] && sieve[n - i]){
	cout << n << " = " << i << " + " << n - i << endl;
	break;
      }
  }
  return 0;
}