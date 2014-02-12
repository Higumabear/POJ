/*
 * 3616.cpp
 *
 * Last update: <12/24/2012 00:44:04>
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

int dp[1001];
int interval[1000][3];

struct milk{
  int in, out, ef;
  
  bool operator<(const milk e)const{
    return in < e.in;
  }
}milk[1000];


int main(){
  fill(dp, dp + 1001, 0);
  int N, M, R; cin >> N >> M >> R;
  
  for(int i = 0; i < M; i++){
    cin >> milk[i].in >> milk[i].out >> milk[i].ef;
  }

  sort(milk, milk + M);

  for(int i = 0; i < M; i++){
    dp[i] = milk[i].ef;
  }

  for(int i = 0; i < M; i++){
    for(int j = i + 1; j < M; j++){
      if(milk[j].in >= milk[i].out + R)
	dp[j] = max(dp[j], dp[i] + milk[j].ef);
    }
  }

  cout << *max_element(dp, dp + M) << endl;
  return 0;
}