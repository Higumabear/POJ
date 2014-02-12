// last update : 2013-04-01 07:50:11 nav

#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
typedef long long ll;

#define ALL(a)  (a).begin(),(a).end()

const int INF = 1 << 29;
const double EPS = 1e-7;

int main(int argc, char **argv){
  int N;
  cin >> N;
  for(int k = 1; k <= N; k++){
    string s, t, ans;
    cin >> s >> t;
    int carry = 0;
    reverse(ALL(s));
    reverse(ALL(t));
    if(s.length() < t.length()) swap(s, t);
    t += string(s.length() - t.length(), '0');

    int i;
    for(i = 0; i < min(s.length(), t.length()); i++){
      int bs = s[i] - '0';
      int bt = t[i] - '0';
      int c = bs + bt + carry;
      switch(c){
      case 0:
	carry = 0;
	ans += '0';
	break;
      case 1:
	carry = 0;
	ans += '1';
	break;
      case 2:
	carry = 1;
	ans += '0';
	break;
      case 3:
	carry = 1;
	ans += '1';
	break;
      }
    }
    if(carry == 1) ans += '1';
    reverse(ALL(ans));
    string ans_;
    int j;
    for(j = 0; ans[j] == '0'; j++);
    ans_ = ans.substr(j);
    cout << k << " " 
	 << (ans_.empty() ? "0" : ans_) << endl;
  }
}