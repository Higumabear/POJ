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
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    cout << i + 1 << " ";
    cout << a / 25 << " QUARTER(S), ";
    a %= 25;
    cout << a / 10 << " DIME(S), ";
    a %= 10;
    cout << a / 5 << " NICKEL(S), ";
    a %= 5;
    cout << a  << " PENNY(S)" << endl; 
  }
  return 0;
}
