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
  string t;
  cin >> t;

  int N = t.length();
  int res = 0;
  int pos;
  for(int j = 0; j < N; j++){
    if(t[j] == '?') pos = j;
    else if(t[j] == 'X') res += 10 * (N - j);      
    else res += (t[j] - '0') * (N - j);
  }

  int ans = -1;
  for(int i = 0; i <= (pos == 9 ? 10 : 9); i++){
    if((res + i * (10 - pos)) % 11 == 0){
      ans = i;
      break;
    }
  }
  if(ans == 10) cout << "X" << endl;
  else cout << ans << endl;
  return 0;
}