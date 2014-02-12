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
    string a;
    cin >> a;
    int N = a.length();
    int cons = 1;
    for(int j = 1; j < N; j++){
      if(a[j - 1] != a[j]){
	cout << cons << a[j - 1];
	cons = 1;
      }
      else cons++;
    }
    cout << cons << a[N - 1] << endl;
  }
  return 0;
}
