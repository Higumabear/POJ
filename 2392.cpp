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
#include <numeric>
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;

struct block{
  int h, a, c;
  bool operator<(const block &r)const{
    return a < r.a;
  }
};

block b[410];
bool dp[50000];

int main(){
  int K; cin >> K;
  for(int i = 0; i < K; i++) {
    cin >> b[i].h >> b[i].a >> b[i].c;
  }

  sort(b, b + K);
  int ans = 0;
  dp[0] = true;
  for(int i = 0; i < K; i++){
    for(int j = 40000; j >= 0; j--){
      if(dp[j]){
	for(int k = 1; k <= b[i].c; k++){
	  if(j + k * b[i].h > b[i].a) break;
	  dp[j + k * b[i].h] = true;
	  ans = max(ans, j + k * b[i].h);
	}
      }
    }
  }
  cout << ans << endl;
  return 0;
}