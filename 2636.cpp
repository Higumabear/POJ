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
#include <numeric>
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;

int main(){
  int n; cin >> n;
  while(n--){
    int d; cin >> d;
    vector<int> tap(d);
    for(int i = 0; i < d; i++) cin >> tap[i];
    sort(tap.begin(), tap.end(), greater<int>());

    int outlet = 0;
    for(int i = 0; i < d; i++){
      outlet += tap[i];
      if(i != 0) outlet -= 1;
      if(outlet >= d - i - 1){
	cout << outlet - (d - i - 1) + 
	  accumulate(tap.begin() + i + 1, tap.end(), 0) << endl;
	break;
      }
    }
  }
  return 0;
}