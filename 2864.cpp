// Time-stamp: <Wed Oct 05 22:26:46 東京 (標準時) 2016>
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

int at[101];
int main(int argc, char **argv){
  int N, D;
  while(cin >> N >> D, N | D){
    FILL(at, 0);
    bool ok = false;
    for(int i = 0; i < D; i++){
      for(int j = 0; j < N; j++){
	int a; cin >> a;
	at[j] += a;
	if(at[j] == D) ok = true;
      }
    }
    cout << (ok ? "yes" : "no") << endl;
  }
  return 0;
}
