// Time-stamp: <Wed Dec 21 23:37:30 東京 (標準時) 2016>
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

int decode(string s){
  reverse(ALL(s));

  int ret = 0, tmp = 0;
  for(int i = 0; i < s.size(); i++){
    if(isalpha(s[i]) && tmp) ret += tmp;
    if(s[i] == 'i') tmp = 1;
    else if(s[i] == 'x') tmp = 10;
    else if(s[i] == 'c') tmp = 100;
    else if(s[i] == 'm') tmp = 1000;
    else {
      tmp *= (int)(s[i] - '0');
      ret += tmp;
      tmp = 0;
    }
  }
  ret += tmp;
  return ret;
}

char *d = "0123456789";
string encode(int x){
  string ret;
  char c[5] = {'i', 'x', 'c', 'm'};
  for(int i = 0; i < 4; i++){
    int a = x % 10;
    if(a){
      ret += c[i];
      if(a > 1) ret.push_back(d[a]);
    }
    x /= 10;
  }
  reverse(ALL(ret));
  return ret;
}

int main(int argc, char **argv){
  int T;
  cin >> T;
  while(T--){
    string x, y;
    cin >> x >> y;
    cout << encode(decode(x) + decode(y)) << endl;
  }
  return 0;
}
