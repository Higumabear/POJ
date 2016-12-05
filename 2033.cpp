// Time-stamp: <Mon Dec 05 22:09:15 東京 (標準時) 2016>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 60
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define CNT(c,x) count(ALL(c),x)
#define dump(x)  cerr << #x << " = " << (x) << endl;
template<typename A, size_t N, typename T>
void FILL(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

using namespace std;

int main(int argc, char **argv){
  string s;
  while(cin >> s){
    if(s == "0") break;
    
    ll dp[1000000];
    FILL(dp, 0);
    dp[0] = 1;
    for(int i = 0; i < s.size(); i++){
      if(s[i] != '0') dp[i + 1] += dp[i];
      if(i - 1 >= 0 && (s[i - 1] - '0' != 0) && 
	 (s[i] - '0') + 10 * (s[i - 1] - '0') <= 26)
	dp[i + 1] += dp[i - 1];
    }
    cout << dp[s.size()] << endl;
  }
  return 0;
}
