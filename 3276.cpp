// Time-stamp: <Tue May 16 23:11:28 東京 (標準時) 2017>
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

int N;
int f[5001];
int fb[5001];

int flip(int K){
  int res = 0, sum = 0;
  FILL(f, 0);
  for(int i = 0; i + K - 1 < N; i++){
    if((sum + fb[i]) % 2 == 1){ // B
      res++;
      f[i] = 1;
    }
    sum += f[i];
    if(i - K + 1 >= 0) sum -= f[i - K + 1];
  }
  for(int i = N - K + 1; i < N; i++){
    if((fb[i] + sum) % 2 == 1) return -1;
    if(i - K + 1 >= 0) sum -= f[i - K + 1];
  }
  return res;
}

int main(int argc, char **argv){
  cin >> N;
  for(int i = 0; i < N; i++){
    char c; cin >> c;
    fb[i] = c == 'B';
  }

  int K = 1, M = N;
  for(int k = 1; k <= N; k++){
    int m = flip(k);
    if(m >= 0 && M > m){
      M = m;
      K = k;
    }
  }
  cout << K << " " << M << endl;
  return 0;
}
