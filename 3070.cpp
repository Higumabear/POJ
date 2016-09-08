#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
#define INF 1 << 29

typedef vector<int> vec;
typedef vector<vec> mat;

const int mod = 10000;

mat identity(int n){
  mat E(n, vec(n, 0));
  for(int i = 0; i < n; i++) E[i][i]++;
  return E;
}

mat mult(mat A, mat B){
  int L = A.size(), M = A[0].size(), N = B[0].size();
  mat C(L, vec(N, 0));
  for(int i = 0; i < L; i++)
    for(int k = 0; k < N; k++)
      for(int j = 0; j < M; j++)
	C[i][k] = (C[i][k] + A[i][j] * B[j][k]) % mod;
  return C;
}

mat pow(mat A, int n){
  if(n == 0) return identity(A.size());
  mat ret = pow(mult(A, A), n / 2);
  if(n % 2 == 1)
    ret = mult(ret, A);
  return ret;
}

int main(int argc, char **argv){
  int n;
  while(cin >> n, n >= 0){
    mat A(2, vec(2, 1));
    A[1][1] = 0;
    
    mat ret = pow(A, n);
    cout << ret[0][1] % mod << endl;
  }
  return 0;
}
