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

int dp[101][101];

void print_lcs(int i, int j, vector<string> &s, vector<string> &t){
  if(i == 0 || j == 0) return;
  if(s[i - 1] == t[j - 1]){
    print_lcs(i - 1, j - 1, s, t);
    cout << s[i - 1] << " ";
  }else{
    if(dp[i - 1][j] >= dp[i][j - 1])
      print_lcs(i - 1, j, s, t);
    else
      print_lcs(i, j - 1, s, t);
  }
}

int main(){
  while(1){
    vector<string> s, t;
    string tmp;
    while(1){
      if(!(cin >> tmp)) return 0;
      if(tmp == "#") break;
      s.push_back(tmp);
    }
    while(1){
      cin >> tmp;
      if(tmp == "#") break;
      t.push_back(tmp);
    }
    
    int N = s.size();
    int M = t.size();
    
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
	if(s[i] == t[j])
	  dp[i + 1][j + 1] = dp[i][j] + 1;
	else
	  dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
    
    print_lcs(N, M, s, t);
    cout << endl;
  }
  return 0;
}