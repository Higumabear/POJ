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
  int n; cin >> n;
  while(n--){
    int a,b,c;
    cin >> a >> b >> c;
    if(a < b - c) cout << "advertise" << endl;
    else if(a > b - c) cout << "do not advertise" << endl;
    else cout << "does not matter" << endl;
  }
  return 0;
}