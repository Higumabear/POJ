/*
 * 1579.cpp
 *
 * Last update: <11/17/2012 21:12:38>
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
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;

int dp[100][100][100];

int rec(int a, int b, int c){
  if(a <= 0 || b <= 0 || c <= 0) return 1;
  if(dp[a][b][c] != -1) return dp[a][b][c];

  if(a > 20 || b > 20 || c > 20) return dp[a][b][c] = rec(20, 20, 20);
  if(a < b && b < c)
    return dp[a][b][c] = rec(a, b, c - 1) + rec(a, b - 1, c - 1) - rec(a, b - 1, c);

  return dp[a][b][c] = rec(a-1, b, c) + rec(a-1, b-1, c) + rec(a-1, b, c-1) - rec(a-1, b-1, c-1);
}

int main(){
  for(int i = 0; i < 100; i++)
    for(int j = 0; j < 100; j++)
      for(int k = 0; k < 100; k++)
	dp[i][j][k] = -1;

  int a, b, c;
  while(cin >> a >> b >> c){
    if(a == -1 && b == -1 && c == -1) break;
    cout << "w(" << a << ", " << b << ", " << c << ") = " << rec(a, b, c) << endl;
  }
  return 0;
}