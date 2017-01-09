// Time-stamp: <Wed Dec 14 21:55:10 東京 (標準時) 2016>
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

int main(int argc, char **argv){
  int N, C;
  while(cin >> N >> C){
    if(N * C == 0) cout << 0 << endl;
    else{
      if(C % (2 * N) == N)
	cout << (C / (2 * N)) << endl;
      else
	cout << (int)(0.5 + C * 1.0 / (2 * N)) << endl;
    }
  }
  return 0;
}
