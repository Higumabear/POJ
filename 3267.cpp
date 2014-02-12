#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

int dp[301];
string dic[600];
int W, L;
string message; 

int main(int argc, char **argv){
  cin >> W >> L >> message;
  for(int i = 0; i < W; i++) cin >> dic[i];

  memset(dp, 0, sizeof(dp));
  for(int i = 1; i <= L; i++){
    dp[i] = dp[i - 1] + 1;
    for(int j = 0; j < W; j++){
      int p = i - 1;
      int len = dic[j].length();
      while(p >= 0 && len > 0)
	if(message[p--] == dic[j][len - 1]) len--;

      if(len == 0)
	dp[i] = min(dp[i],
		    dp[p + 1] + i - p - 1 - (int)dic[j].length());
    }
  }
  cout << dp[L] << endl;
  return 0;
}