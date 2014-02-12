#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

int dp[100001];

int main(int argc, char **argv){
  int M, N;
  while(cin >> M >> N){
    if(N == 0 && M == 0) break;

    //Input
    map<string, vector<int> > shirt;
    string color;
    int time;
    for(int i = 0; i < M; i++) cin >> color;
    for(int i = 0; i < N; i++){
      cin >> time >> color;
      shirt[color].push_back(time);
    }

    int ans = 0;

    //Wash same color clothes
    for(map<string, vector<int> >::iterator it = shirt.begin();
	  it != shirt.end(); it++){

      vector<int> tmp = it -> second;

      //DP
      sort(tmp.begin(), tmp.end());
      int total = accumulate(tmp.begin(), tmp.end(), 0);
      memset(dp, -1, sizeof(dp));
      dp[0] = 0;
      for(int i = 0; i < (int)tmp.size(); i++){
	for(int j = 0; j <= total; j++){
	  if(dp[j] >= 0)
	    dp[j] = 1;
	  else if(j < tmp[i] || dp[j - tmp[i]] <= 0)
	    dp[j] = -1;
	  else
	    dp[j] = dp[j - tmp[i]] - 1;
	}
      }

      //Shortest time to wash same color clothes by two people
      int i;
      for(i = (total + 1) / 2; i <= total; i++)
	if(dp[i] >= 0)
	  break;
    
      ans += i;
    }
    
    cout << ans << endl;
  }
  return 0;
}