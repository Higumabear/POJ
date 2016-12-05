// Time-stamp: <Sat Sep 10 01:56:41 東京 (標準時) 2016>
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

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a % b); }
int main(int argc, char **argv){
  string s, t;
  while(cin >> s){
    if(s == "-1") break;
    cin >> t;
    
    int mval = 0;
    for(int k = 0; k < 2; k++){
      for(int i = 0; i < s.size(); i++){
	int cnt = 0;
	string u = string(i, '*') + t;
	for(int j = 0; j < min(s.size(), u.size()); j++)
	  if(s[j] == u[j] && s[j] != '*') cnt++;
	mval = max(mval, cnt);
      }
      swap(s, t);
    }
    mval *= 2;
    cout << "appx(" << s << "," << t << ") = ";
    if(mval == 0) cout << 0;
    else if(mval == s.size() + t.size()) cout << 1;
    else{
      int g = gcd(mval, s.size() + t.size());
      cout << mval / g << "/" << (s.size() + t.size()) / g;
    }
    cout << endl;
  }
  return 0;
}
