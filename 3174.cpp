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

int x[770], y[770];

bool collinear(int a, int b, int c){
  int x1 = x[b] - x[a];
  int y1 = y[b] - y[a];
  int x2 = x[c] - x[a];
  int y2 = y[c] - y[a];
  return x1 * y2 == x2 * y1;
}

int main(){
  int n; cin >> n;
  for(int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
  }

  int cnt = 0;
  vector<int> a,b,c;
  for(int i = 0; i < n; i++)
    for(int j = i + 1; j < n; j++)
      for(int k = j + 1; k < n; k++)
	if(collinear(i, j, k)){
	  a.push_back(i + 1);
	  b.push_back(j + 1);
	  c.push_back(k + 1);
	  cnt++;
	}

  cout << cnt << endl;
  for(int i = 0; i < cnt; i++){
    cout << a[i] << " " << b[i] << " " << c[i] << endl;
  }
  return 0;
}