// Time-stamp: <Sat Oct 29 22:43:20 東京 (標準時) 2016>
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

string f[23] = {
  string("         _         "),
  string("       _*g+_       "),
  string("     _* +_* +_     "),
  string("   _*e+_*m+_* +_   "),
  string(" _* +_* +_* +_* +_ "),
  string("* +_* +_* +_* +_* +"),
  string("+_*C+_* +_* +_* +_*"),
  string("* +_* +_* +_* +_*s+"),
  string("+_* +_* +_* +_*a+_*"),
  string("* +_* +_* +_* +_* +"),
  string("+_* +_*h+_* +_* +_*"),
  string("* +_*S+_* +_* +_* +"),
  string("+_* +_* +_* +_* +_*"),
  string("* +_* +_* +_* +_* +"),
  string("+_* +_* +_* +_* +_*"),
  string("*S+_* +_* +_* +_* +"),
  string("+_* +_* +_* +_*A+_*"),
  string("* +_* +_* +_* +_* +"),
  string("+_* +_* +_* +_* +_*"),
  string("  +_* +_*G+_* +_*  "),
  string("    +_* +_* +_*    "),
  string("      +_* +_*      "),
  string("        +_*        "),
};

int main(int argc, char **argv){
  int n;
  while(cin >> n, n){
    for(int i = 0; i < 23; i++)
      for(int j = 0; j < f[i].size(); j++)
	if(isalpha(f[i][j])) f[i][j] = ' ';

    string s;
    char c;
    for(int i = 0; i < n; i++){
      cin >> s >> c;
      char xc;
      int y;
      sscanf(s.c_str(), "%c%d", &xc, &y);
      int x = (int)(xc - 'A');

      int offset = abs(x - 4);
      y = 10 - offset - y;
      //cout << c << " " << 1 + offset + 2 * y << " " << 2 * x + 1 << endl;
      f[offset + 1 + y * 2][2 * x + 1] = c;
    }
    for(int i = 0; i < 23; i++){
      for(int j = 0; j < f[i].size(); j++){
	if(f[i][j] == '+') f[i][j] = '\\';
	if(f[i][j] == '*') f[i][j] = '/';
      }
      cout << f[i] << endl;
    }
  }
  return 0;
}
