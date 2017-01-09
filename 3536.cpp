// Time-stamp: <Sun Dec 25 22:12:17 東京 (標準時) 2016>
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

int sur, A, B, C;
vector<int> r;
vector<int> f(int n){
  vector<int> ret;
  for(int i = 2; i * i <= n; i++){
    while(n % i == 0){
      n /= i;
      ret.push_back(i);
    }
  }
  if(n != 1) ret.push_back(n);
  return ret;
}
void check(int a, int b, int c){
  if(sur > a * b + b * c + c * a){
    sur = a * b + b * c + c * a;
    A = a, B = b, C = c;
  }
  return;
}
void rec(int idx, int a, int b, int c){
  if(idx == r.size()){
    check(a, b, c);
    return;
  }
  rec(idx + 1, a * r[idx], b, c);
  rec(idx + 1, a, b * r[idx], c);
  rec(idx + 1, a, b, c * r[idx]);
  return;
}
int main(int argc, char **argv){
  int N;
  while(cin >> N){
    r = f(N);
    sur = INF;
    rec(0, 1, 1, 1);
    cout << A << " " << B << " " << C << endl;
  }
  return 0;
}
