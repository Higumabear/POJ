// Time-stamp: <Sat Jan 28 01:59:40 東京 (標準時) 2017>
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

mat add_res;

int MOD;

inline mat identity(int n){
  mat E(n, vec(n, 0));
  for(int i = 0; i < n; i++) E[i][i] = 1;
  return E;
}

inline void add(const mat &A, const mat &B){
  int N = A.size(), M = A[0].size();
  for(int n = 0; n < N; n++)
    for(int m = 0; m < M; m++)
      add_res[n][m] = ((A[n][m] + B[n][m]) % MOD);
}

inline mat mult(const mat &A, const mat &B){
  int N = A.size(), M = B.size(), L = B[0].size();
  mat C(N, vec(L, 0));
  for(int n = 0; n < N; n++)
    for(int l = 0; l < L; l++)
      for(int m = 0; m < M; m++)
	C[n][l] = ((C[n][l] + A[n][m] * B[m][l]) % MOD);
  return C;
}

inline mat pow(const mat &A, int p){
  mat R = identity(A.size());
  mat B = A;
  while(p){
    if(p & 1) R = mult(R, B);
    B = mult(B, B);
    p >>= 1;
  }
  return R;
}

map<int, mat> memo;

mat rec(const mat &A, int w){
  if(w == 1) return identity(A.size());
  if(memo.count(w)) return memo[w];

  mat L = rec(A, w / 2);
  mat R = L;
  mat B = pow(A, w / 2);
  R = mult(B, R);
  
  add(L, R);
  if(w % 2) add(add_res, pow(A, w - 1));
  return memo[w] = add_res;
}

int main(int argc, char **argv){
  int n, k, m;
  scanf("%d %d %d", &n, &k, &m);
  MOD = m;
  mat A = identity(n);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      scanf("%ld", &A[i][j]);
  
  add_res = identity(n);

  mat ans = rec(A, k);
  ans = mult(A, ans);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      printf("%ld ", ans[i][j] % MOD);
    }
    printf("\n");
  }
  return 0;
}
