// Time-stamp: <Sun Sep 11 15:39:26 東京 (標準時) 2016>
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

int sum[1000000];
int num[50];
int deci[6] = {1, 10, 100, 1000, 10000, 100000};
int main(int argc, char **argv){
  int k; cin >> k;
  for(int i = 0; i < deci[k / 2]; i++){
    int s = 0, v = i;
    while(v){
      s += (v % 10);
      v /= 10;
    }
    num[s]++;
    sum[i] = s;
  }
  int ans = 0;
  for(int i = 0; i < deci[k / 2]; i++){
    //cout << i << " " << sum[i] << " " << num[sum[i]] << endl;
    ans += num[sum[i]];
  }
  cout << ans << endl;
  return 0;
}