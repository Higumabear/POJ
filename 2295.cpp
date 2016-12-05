// Time-stamp: <Tue Nov 15 23:52:13 東京 (標準時) 2016>
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

void strReplace(string &str, const string &from, const string &to){
  string::size_type pos = 0;
  while((pos = str.find(from, pos)) != string::npos){
    str.replace(pos, from.length(), to);
    pos += to.length();
  }
}

int s2i(string s){
  stringstream ss(s);
  int x; ss >> x; return x;
}

void proc(string s, int &coef, int &cons){
  stringstream ss(s);
  string tmp;
  while(ss >> tmp){
    if(tmp[tmp.size() - 1] == 'x'){
      if(tmp == "x") coef += 1;
      else if(tmp == "-x") coef += -1;
      else coef += s2i(tmp.substr(0, tmp.size() - 1));
    }
    else cons += s2i(tmp);
  }
  return;
}

int main(int argc, char **argv){
  int t; cin >> t;
  while(t--){
    string s;
    cin >> s;
    strReplace(s, "=", " ");
    stringstream ss(s);
    
    string l, r;
    ss >> l >> r;
    strReplace(l, "-", " -");
    strReplace(l, "+", " ");
    strReplace(r, "-", " -");
    strReplace(r, "+", " ");

    int lcoef = 0, lcons = 0, rcoef = 0, rcons = 0;
    proc(l, lcoef, lcons);
    proc(r, rcoef, rcons);
    // dump(lcoef);
    // dump(lcons);
    // dump(rcoef);
    // dump(rcons);
    if(lcoef == rcoef)
      cout << (lcons == rcons ? "IDENTITY" : "IMPOSSIBLE") << endl;
    else
      cout << (int)floor((rcons - lcons) * 1.0 / (lcoef - rcoef)) << endl;
  }
  return 0;
}
