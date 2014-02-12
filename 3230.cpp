#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 1 << 29;

int dp[101][101];
int cost[100][100];
int income[100][100];
int n, m;

int main(){
  while(scanf("%d %d", &n, &m) != EOF){
    if(n == 0 && m == 0) break;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
	scanf("%d", &cost[i][j]);
    
    for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
	scanf("%d", &income[i][j]);
	
    for(int i = 0; i < 101; i++)
      for(int j = 0; j < 101; j++)
	dp[i][j] = -INF;


    dp[0][0] = 0;
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
	for(int k = 0; k < n; k++){
	  dp[j][i + 1] = max(dp[j][i + 1], dp[k][i] - cost[k][j] + income[i][j]);
	}  
      }
    }
      
    int ans = -INF;
    for(int i = 0; i < n; i++) ans = max(ans, dp[i][m]);
    printf("%d\n", ans);
  }
  return 0;
}