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

typedef vector<long long> vec;
typedef vector<vec> mat;


map<ll, ll> factorize(ll n){
  map<ll, ll> pf;
  for(ll i = 2LL; i * i <= n; i++){
    while(n % i == 0){
      pf[i]++;
      n /= i;
    }
  }
  if(n != 1) pf[n]++;
  return pf;
}

mat identity(ll n){
  mat I(n, vec(n, 0));
  for(ll i = 0; i < n; i++) I[i][i] = 1;
  return I;
}

mat mul(const mat &A, const mat &B, ll mod){
  mat C(A.size(), vec(B[0].size(), 0));
  for(ll i = 0; i < A.size(); i++)
    for(ll k = 0; k < A[0].size(); k++)
      for(ll j = 0; j < B[0].size(); j++)
	C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
  return C;
}

mat pow(const mat &A, ll p, ll mod){
  if(p == 0) return identity(A.size());
  if(p == 1) return A;
  mat B = pow(mul(A, A, mod), p / 2, mod);
  if(p % 2 == 1) B = mul(B, A, mod);
  return B;
}

int main(){
  ll A, B;
  cin >> A >> B;
  if(A == 0LL){
    cout << (B == 0LL ? 1 : 0) << endl;
    return 0;
  }
  

  map<ll, ll> pf = factorize(A);
  map<ll, ll>::iterator it = pf.begin();

  ll ans = 1;
  for(; it != pf.end(); it++){
    mat a = identity(2);
    a[0][0] = it->first;
    a[1][0] = 1;
    mat ret = pow(a, it->second * B, 9901);
    ans = (ans * (ret[1][0] + ret[0][0]) % 9901) % 9901;
  }
  cout << ans << endl;
  return 0;
}