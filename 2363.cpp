// Time-stamp: <Sun Sep 11 01:24:36 東京 (標準時) 2016>
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

vector<int> d;
int rec(int idx, int a, int b, int c){
  if(idx == d.size()) return 2 * (a * b+ b * c + c * a);
  
  int ret = INF;
  ret = min(ret, rec(idx + 1, a * d[idx], b, c));
  ret = min(ret, rec(idx + 1, a, b * d[idx], c));
  ret = min(ret, rec(idx + 1, a, b, c * d[idx]));
  return ret;
}

int main(int argc, char **argv){
  int C; cin >> C;
  while(C--){
    int N; cin >> N;
    d.clear();
    d.push_back(1);
    d.push_back(1);
    d.push_back(1);
    for(int i = 2; i <= N; i++){
      while(N % i == 0){
	d.push_back(i);
	N /= i;
      }
    }
    cout << rec(0, 1, 1, 1) << endl;
  }
  return 0;
}
