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

int dp[5001];
int cnt[5001];
int a[5000];
int main(){
  int N;
  scanf("%d", &N);
  for(int i = 0; i < N; i++)
    scanf("%d", &a[i]);

  for(int i = 0; i < N; i++){
    dp[i] = 1;
    cnt[i] = 1;
    for(int j = i - 1; j >= 0; j--)
      if(a[j] > a[i]){
	if(dp[j] + 1 > dp[i]){
	  dp[i] = dp[j] + 1;
	  cnt[i] = cnt[j];
	}else if(dp[j] + 1 == dp[i])
	  cnt[i] += cnt[j];
      }else if(a[i] == a[j]){
	if(dp[i] == 1) cnt[i] = 0;
	break;
      }
  }

  int len = *max_element(dp, dp + N);
  int count = 0;
  for(int i = 0; i < N; i++){
    if(dp[i] == len)
      count += cnt[i];
  }
  printf("%d %d\n", len, count);
  return 0;
}