// Time-stamp: <Mon Aug 29 23:30:07 東京 (標準時) 2016>
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

typedef vector<int> vec;
typedef vector<vec> mat;

const int MOD = 10007;

mat identity(int n){
  mat E(n, vec(n, 0));
  for(int i = 0; i < n; i++) E[i][i] = 1;
  return E;
}

mat mult(const mat &A, const mat &B){
  int N = A.size(), M = B.size(), L = B[0].size();
  mat C(N, vec(L, 0));
  for(int n = 0; n < N; n++)
    for(int l = 0; l < L; l++)
      for(int m = 0; m < M; m++)
	C[n][l] += ((A[n][m] * B[m][l]) % MOD);
  return C;
}

mat pow(const mat &A, int p){
  mat R = identity(A.size());
  mat B = A;
  while(p){
    if(p & 1) R = mult(R, B);
    B = mult(B, B);
    p >>= 1;
  }
  return R;
}

int main(int argc, char **argv){
  mat A(3, vec(3));
  A[0][0] = 2, A[0][1] = 1, A[0][2] = 0;
  A[1][0] = 2, A[1][1] = 2, A[1][2] = 2;
  A[2][0] = 0, A[2][1] = 1, A[2][2] = 2;

  int T; cin  >> T;
  while(T--){
    int N; cin >> N;
    mat C = pow(A, N);
    cout << C[0][0] % MOD << endl;
  }
  return 0;
}
