#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

typedef long long ll;

ll powmod(ll a, int n, ll mod){
  ll ret = 1;
  while(n){
    if(n & 1) ret = (ret * a) % mod;
    a = (a * a) % mod;
    n >>= 1;
  }
  return ret;
}

int main(int argc, char **argv){
  int T; cin >> T;
  while(T--){
    int M; cin >> M;
    int N; cin >> N;

    ll r = 0;
    for(int i = 0; i < N; i++){
      int a, b;
      cin >> a >> b;
      r = (r + powmod(a, b, M)) % M;
    }
    cout << r % M << endl;
  }
}
