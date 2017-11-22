// Time-stamp: <Sat Feb 04 22:07:57 東京 (標準時) 2017>
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

string s[8];
int main(int argc, char **argv){
  s[1] = "X";
  s[2] = "X X X X X";
  for(int i = 3; i <= 7; i++){
    int prevw = pow(3, (i - 2));
    for(int y = 0; y < prevw; y++){
      string p = s[i - 1].substr(y * prevw, prevw);
      s[i] += p + string(prevw, ' ') + p;
    }
    for(int y = 0; y < prevw; y++){
      string p = s[i - 1].substr(y * prevw, prevw);
      s[i] += string(prevw, ' ') + p + string(prevw, ' ');
    }
    for(int y = 0; y < prevw; y++){
      string p = s[i - 1].substr(y * prevw, prevw);
      s[i] += p + string(prevw, ' ') + p;
    }
  }
  int n;
  while(cin >> n){
    if(n == -1) break;
    int w = pow(3, n - 1);
    for(int i = 0; i < w; i++) 
      cout << s[n].substr(i * w, w) << endl;
    cout << "-" << endl;
  }
  return 0;
}
