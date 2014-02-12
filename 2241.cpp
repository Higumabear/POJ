/*
 * 2241.cpp
 *
 * Last update: <2012年/12月/28日 22時59分38秒>
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[200];

int main(int argc, char **argv){
  int n;
  int k = 0;
  while(cin >> n, n > 0){
    k++;
    vector<pair<pair<int, int>, int> > data;
    for(int i = 0; i < n; i++){
      int in[3];
      cin >> in[0] >> in[1] >> in[2];
      sort(in, in + 3);
      do{
	data.push_back(make_pair(make_pair(in[0], in[1]), in[2]));
      }while(next_permutation(in, in + 3));
    }

    sort(data.begin(), data.end());

    memset(dp, 0, sizeof(dp));
    
    int ans = 0;
    for(int i = 0; i < (int)data.size(); i++){
      dp[i] = data[i].second;
      for(int j = 0; j < i; j++){
	if(data[j].first.first < data[i].first.first
	   && data[j].first.second < data[i].first.second)
	  dp[i] = max(dp[i], dp[j] + data[i].second);
      }
      ans = max(dp[i], ans);
    }
    cout << "Case " << k << ": maximum height = " << ans << endl;
  }
  return 0;
}