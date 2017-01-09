// Time-stamp: <Fri Jan 06 22:36:56 東京 (標準時) 2017>
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

bool prime[100001];

int main(int argc, char **argv){
  FILL(prime, true);
  prime[0] = prime[1] = false;
  for(int i = 2; i * i <= 100000; i++){
    if(prime[i])
      for(int j = 2 * i; j <= 100000; j += i) prime[j] = false;
  }
  vector<int> pr;
  for(int i = 0; i <= 100000; i++)
    if(prime[i]) pr.push_back(i);
  int l, r;
  while(cin >> l >> r){
    if(l == -1 && r == -1) break;
    cout << upper_bound(ALL(pr), r) - lower_bound(ALL(pr), l) << endl;
  }
  return 0;
}
