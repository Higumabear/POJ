// Time-stamp: <Thu Nov 10 00:10:39 東京 (標準時) 2016>
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

string i2s(ll i){
  stringstream ss;
  ss << i;
  return ss.str();
}

int main(int argc, char **argv){
  ll r;
  while(cin >> r, r){
    ll sum = 0;
    int d;
    for(d = 1; d <= 20; d++){
      ll total = 9LL * pow(10L, (d - 1) / 2);
      if(sum + total >= r) break;
      else sum += total;
    }
    r -= sum;
    ll s = pow(10LL, (d - 1) / 2) + r - 1;

    string ret = i2s(s);
    cout << ret;
    reverse(ALL(ret));
    if(d % 2 == 1)
      cout << ret.substr(1) << endl;
    else
      cout << ret << endl;
  }
  return 0;
}