// Time-stamp: <Wed Jul 26 23:50:58 東京 (標準時) 2017>
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
  int T, N;
  cin >> T;
  while(T--){
    cin >> N;
    int a, b = 0, c = 0;
    for(int i = 0; i < N; i++){
      cin >> a;
      b ^= a;
      c += a;
    }
    if(c == N){
      cout << (c % 2 == 0 ? "John" : "Brother") << endl;
    }else{
      cout << (b ? "John" : "Brother") << endl;
    }
  }
  return 0;
}
