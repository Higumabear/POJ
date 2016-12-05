// Time-stamp: <Sat Oct 29 01:59:11 東京 (標準時) 2016>
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

int main(int argc, char **argv){
  int n, e;
  cin >> n >> e;

  int tmp, sumn = 0, sume = 0;
  for(int i = 0; i < n - 1; i++) cin >> tmp, sumn += tmp;
  for(int i = 0; i < e - 1; i++) cin >> tmp, sume += tmp;
  cout << ceil(sqrt(sumn * sumn + sume * sume)) << endl;
  return 0;
}
