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
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;

int main(){
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  do{
    cout << s << endl;
  }while(next_permutation(s.begin(), s.end()));
  return 0;
}
