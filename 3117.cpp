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
  int T, N;
  while(cin >> T >> N){
    if(T == 0 && N == 0) break;

    int sum = 0;
    string team;
    int p;
    for(int i = 0; i < T; i++){
      cin >> team >> p;
      sum += p;
    }
    cout << 3 * N - sum << endl;
  }
  return 0;
}
