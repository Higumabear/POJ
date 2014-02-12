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
const int INF = 1 << 28;

struct Board{
  int X1, X2, H;
  bool operator<(const Board &e)const{
    return H < e.H;
  }
};

Board b[1050];
int dp[1050][2];

int main(){
  int T; cin >> T;
  while(T--){
    //Input
    int N, X, Y, MAX;
    cin >> N >> X >> Y >> MAX;
    b[0].X1 = X; b[0].X2 = X; b[0].H = Y; //Start point
    b[N + 1].X1 = -INF; b[N + 1].X2 = INF; b[N + 1].H = 0;
    for(int i = 1; i <= N; i++)
      cin >> b[i].X1 >> b[i].X2 >> b[i].H;

    sort(b, b + N + 2);
    //reverse(b, b + N + 2);

    //Initialize
    // for(int i = 0; i <= N + 1; i++)
    //   for(int j = 0; j < 2; j++)
    // 	dp[i][j] = INF;

    // dp[0][0] = dp[0][1] = 0;

    //DP
    for(int i = 1; i <= N + 1; i++){
      for(int j = i - 1; j >= 0; j--){
	//reachable from the left-end of b[j] onto b[i] 
	if(b[j].X1 <= b[i].X1 && b[i].X1 <= b[j].X2){
	  if(abs(b[j].H - b[i].H) > MAX)
	    dp[i][0] = INF;
	  else if(j == 0)
	    dp[i][0] = b[i].H - b[j].H;
	  else
	    dp[i][0] = min(dp[j][0] 
			   + abs(b[i].H - b[j].H) 
			   + abs(b[i].X1 - b[j].X1),
			   dp[j][1] 
			   + abs(b[i].H - b[j].H) 
			   + abs(b[i].X1 - b[j].X2));
	  break;
	}
      }
      for(int j = i - 1; j >= 0; j--){
	//reachable from the right-end of b[j] onto b[i]
	if(b[j].X1 <=  b[i].X2 && b[i].X2 <= b[j].X2 ){
	  if(abs(b[j].H - b[i].H) > MAX)
	    dp[i][1] = INF;
	  else if(j == 0)
	    dp[i][1] = b[i].H - b[j].H;
	  else 
	    dp[i][1] = min(dp[j][0]
			   + abs(b[j].H - b[i].H) 
			   + abs(b[i].X2 - b[j].X1),
			   dp[j][1] 
			   + abs(b[j].H - b[i].H) 
			   + abs(b[i].X2 - b[j].X2));
	  break;
	}
      }
    }
      
    cout << min(dp[N + 1][0], dp[N + 1][1]) << endl;
  }
  return 0;
}