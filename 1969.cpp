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
  while(cin >> n){
    
    int r = 1;
    for(;;){
      if(r * (r + 1) / 2 >= n) break;
      r++;
    }
    int rem = n - r * (r - 1) / 2;
    if(r % 2 == 0){
      cout << "TERM " << n << " IS " 
	   << rem << "/" << r - rem + 1 << endl;
    }else{
      cout << "TERM " << n << " IS " 
	   << r - rem + 1 << "/" << rem << endl;
    }
  }
  return 0;
}