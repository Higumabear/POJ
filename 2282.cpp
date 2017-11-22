// Time-stamp: <Thu Apr 20 22:53:55 東京 (標準時) 2017>
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

void calc(int n, vector<int> &x){
  if(n == 0) return;
  if(n % 10 == 9){
    vector<int> v(10);
    calc(n / 10, v);
    for(int i = 0; i < 10; i++)
      x[i] += (n + 1) / 10 + v[i] * 10;
    x[0]--;
  }else{
    int t = n;
    while(t){
      x[t % 10]++;
      t /= 10;
    }
    calc(n - 1, x);
  }
}

int main(int argc, char **argv){
  int l, r;
  while(cin >> l >> r, l + r){
    if(l > r) swap(l, r);
    vector<int> a(10), b(10);
    calc(l - 1, a);
    calc(r, b);
    for(int i = 0; i < 10; i++)
      cout << b[i] - a[i] << " ";
    cout << endl;
  }
  return 0;
}
