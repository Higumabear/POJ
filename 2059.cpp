// Time-stamp: <Mon Nov 28 19:05:35 東京 (標準時) 2016>
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
  int N;
  cin >> N;
  while(N--){
    int S, H;
    cin >> S >> H;
    int x[50], y[50];
    for(int i = 0; i < H; i++) cin >> x[i] >> y[i];
    for(int X = 0; X < S; X++){
      for(int Y = 0; Y < S; Y++){
	int minD = min(X, min(Y, min(S - X, S - Y)));
	double maxD = 0;
	for(int i = 0; i < H; i++){
	  if(X == x[i] && Y == y[i]) maxD = 1e100;
	  maxD = max(maxD, sqrt((double)(x[i] - X) * (x[i] - X) + (y[i] - Y) * (y[i] - Y)));
	}
	
	if(maxD <= minD){
	  cout << X << " " << Y << endl;
	  goto L1;
	}
      }
    }
    cout << "poodle" << endl;
  L1:;
  }
  return 0;
}
