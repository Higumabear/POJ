// Time-stamp: <Tue Nov 18 02:34:43 東京 (標準時) 2014>
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

using namespace std;

char c[20] = {'0', '1', '2', '3', '4', '5', '6', '7',
	      '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int d(char c){
  if('0' <= c && c <= '9') return c - '0';
  else return c - 'A' + 10;
}

int main(int argc, char **argv){
  string s;
  int a, b;
  ll p[20][10] = {0};
  for(int i = 0; i <= 16; i++){
    p[i][0] = 1;
    for(int j = 1; j < 9; j++) p[i][j] = i * p[i][j - 1];
  }

  while(cin >> s >> a >> b){
    reverse(ALL(s));

    ll sum = 0;
    for(int i = 0; i < (int)s.length(); i++) sum +=  d(s[i]) * p[a][i];
    string ans;
    while(sum){
      ans += c[sum % b];
      sum /= b; 
    }
    reverse(ALL(ans));
    if(ans.length() >= 8) ans = "ERROR";
    cout << string(7 - ans.length(), ' ') + ans << endl;
  }
  return 0;
}