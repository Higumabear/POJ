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

const ll NUM = 100000;

bool base_sieve[NUM];
bool sieve[1001000];

void segsieve(ll a, ll b){
  FILL(base_sieve, true);
  FILL(sieve, true);
  base_sieve[0] = base_sieve[1] = false;
  for(ll i = 2; i * i <= b; i++){
    if(base_sieve[i]){
      for(ll j = 2 * i; j * j <= b; j += i) base_sieve[j] = false;
      for(ll j = max(2LL, (a + i - 1) / i) * i; j <= b; j += i)
	sieve[j - a] = false;
    }
  }
}

int main(){
  ll L, U;
  
  while(cin >> L >> U){
    segsieve(L, U);
    vector<ll> segment_prime;
    for(ll i = max(L, 2LL); i <= U; i++)
      if(sieve[i - L]) segment_prime.push_back(i);
    if(segment_prime.size() < 2)
      printf("There are no adjacent primes.\n");
    else{
      ll C1 = 0, C2 = LLINF, D1 = 0, D2 = 0;
      for(int i = 1; i < segment_prime.size(); i++){
	if(segment_prime[i] - segment_prime[i - 1] < C2 - C1)
	  C1 = segment_prime[i - 1], C2 = segment_prime[i];
	if(segment_prime[i] - segment_prime[i - 1] > D2 - D1)
	  D1 = segment_prime[i - 1], D2 = segment_prime[i];
      }
      printf("%lld,%lld are closest, %lld,%lld are most distant.\n",
	     C1, C2, D1, D2);
    }
  } 
  return 0;
}
