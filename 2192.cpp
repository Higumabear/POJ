/*
 * 2192.cpp
 *
 * Last update: <12/30/2012 04:04:13>
 */

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

bool dp[201][201];

int main(){
  int n; cin >> n;
  int k = 0;
  while(n--){
    string a, b, c;
    cin >> a >> b >> c;
    
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;
    for(int i = 0; i <= (int)a.length(); i++){
      for(int j = 0; j <= (int)b.length(); j++){
	if(dp[i - 1][j] && (c[i + j - 1] == a[i - 1]))
	  dp[i][j] = true;
	if(dp[i][j - 1] && (c[i + j - 1] == b[j - 1]))
	  dp[i][j] = true;
      }
    }
    cout << "Data set " << ++k << ": " 
	 << (dp[a.length()][b.length()] ? "yes" : "no") << endl;
  }
  return 0;
}