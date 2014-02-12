#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[40001];
int port[40001];

int main(int argc, char **argv){
  int T;
  scanf("%d", &T);
  while(T--){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
      scanf("%d", &port[i]);

    //DP LIS
    fill(dp, dp + n, 1 << 28);
    for(int i = 0; i < n; i++)
      *lower_bound(dp, dp + n, port[i]) = port[i];

    printf("%d\n", lower_bound(dp, dp + n, 1 << 28) - dp);
  }
  return 0;
}
