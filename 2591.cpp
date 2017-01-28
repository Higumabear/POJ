// Time-stamp: <Thu Jan 26 23:45:15 東京 (標準時) 2017>
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
#include <ctime>

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

int  a[10000010];

int main(int argc, char **argv){
  int i2 = 1, i3 = 1;
  a[1] = 1;
  for(int i = 2; i < 10000010; i++){
    a[i] = min(2 * a[i2] + 1, 3 * a[i3] + 1);
    if(a[i] == 2 * a[i2] + 1) i2++;
    if(a[i] == 3 * a[i3] + 1) i3++;
  }
  int t;
  while(cin >> t) cout << a[t] << endl;
  return 0;
}
