#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 10000000;

int h[20];
int w[20];
int dp[21][10000];

int main(){
  int C, G;
  cin >> C >> G;
  for(int i = 0; i < C; i++) cin >> h[i];
  for(int i = 0; i < G; i++) cin >> w[i];

  dp[0][5000] = 1;
  for(int i = 0; i < G; i++){
    for(int j = 0; j < 10000; j++){
      if(dp[i][j]){
	for(int k = 0; k < C; k++){
	  dp[i + 1][j + h[k] * w[i]] += dp[i][j];
	}
      }
    }
  }
  cout << dp[G][5000] << endl;
  return 0;
}