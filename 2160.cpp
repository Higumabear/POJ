// Time-stamp: <Fri Dec 09 00:44:37 東京 (標準時) 2016>
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

vector<int> num;
bool check(){
  if(num[0] != num[1] || num[2] != num[3] || num[4] != num[5]) return false;
  int a[2];
  a[0] = num[0] / 100000; a[1] = num[0] % 100000;
  int b[2];
  b[0] = num[2] / 100000; b[1] = num[2] % 100000;
  int c[2];
  c[0] = num[4] / 100000; c[1] = num[4] % 100000;

  if((a[1] == b[0] && b[1] == c[0] && c[1] == a[0]) || 
     (a[1] == b[0] && b[1] == c[1] && c[0] == a[0]) || 
     (a[1] == b[1] && b[0] == c[0] && c[1] == a[0]) || 
     (a[1] == b[1] && b[0] == c[1] && c[0] == a[0]) || 
     (a[1] == c[0] && c[1] == b[0] && b[1] == a[0]) || 
     (a[1] == c[0] && c[1] == b[1] && b[0] == a[0]) ||
     (a[1] == c[1] && c[0] == b[0] && b[1] == a[0]) ||
     (a[1] == c[1] && c[0] == b[1] && b[0] == a[0])) return true;
  return false;
}
bool rec(int idx, vector<int> a, vector<int> b, vector<int> c){
  //if(idx == 6) return check(a, b, c);
  
  bool ret = false;
  vector<int> t = a;
  t.push_back(idx);
  ret |= rec(idx + 1, t, b, c);
  t = b;
  t.push_back(idx);
  ret |= rec(idx + 1, a, t, c);
  t = c;
  t.push_back(idx);
  ret |= rec(idx + 1, a, b, t);
  return ret;
}
int main(int argc, char **argv){
  for(int i = 0; i < 6; i++){
    int a, b; cin >> a >> b;
    if(a > b) swap(a, b);
    num.push_back(100000 * a + b);
  }
  sort(ALL(num));
  cout << (check() ? "POSSIBLE" : "IMPOSSIBLE") << endl;
  return 0;
}
