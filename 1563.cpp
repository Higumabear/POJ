// Time-stamp: <Mon Dec 05 21:44:02 東京 (標準時) 2016>
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
#define EPS 1e-9
#define ALL(c) (c).begin(), (c).end()
#define CNT(c,x) count(ALL(c),x)
#define dump(x)  cerr << #x << " = " << (x) << endl;
template<typename A, size_t N, typename T>
void FILL(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

using namespace std;

int main(int argc, char **argv){
  int H, U, D, F;
  while(cin >> H >> U >> D >> F, H){
    double h = 0;
    int cnt = 0;
    while(1){
      h = h + U * max(0.0, (1.0 - 0.01 * F * cnt));
      cnt++;
      if(h > H + EPS){
	cout << "success on day " << cnt << endl;
	break;
      }
      h -= D;
      if(h < 0){
	cout << "failure on day " << cnt << endl;
	break;
      }
    }
  }
  return 0;
}
