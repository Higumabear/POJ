// Time-stamp: <Wed Mar 15 00:04:18 東京 (標準時) 2017>
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

bool p[1000002];
int h[250010];
int d[1000002], e[1000002];

int main(int argc, char **argv){
  memset(p, true, sizeof(p));
  p[0] = false;
  for(int i = 1; i <= 250000; i++){
    for(int j = 1; (4 * j + 1) * (4 * j + 1) <= 4 * i + 1; j++){
      if((4 * i + 1) % (4 * j + 1) == 0){
	int v = (4 * i + 1) / (4 * j + 1);
	if((v - 1) % 4 == 0){
	  p[i] = false;
	  break;
	}
      }
    }
  }
  int c = 0;
  for(int i = 0; i <= 250000; i++)
    if(p[i]) h[c++] = 4 * i + 1;

  int idx = 0;
  for(int i = 0; i < c; i++){
    for(int j = 0; j <= i; j++){
      if((ll)h[i] * h[j] > 1000001) break;
      d[idx++] = h[i] * h[j];
    }
  }
  sort(d, d + idx);
  int last = 0;
  e[0] = d[0];
  for(int i = 1; i < idx; i++)
    if(e[last] != d[i]) e[++last] = d[i];
  last++;
  
  // for(int i = 0; i < 100; i++)
  //   cout << i << " " << d[i] << endl;
  //cout << "koko" << endl;

  int N;
  while(cin >> N, N){
    cout << N << " " << (int)(upper_bound(e, e + last, N) - e) << endl;
  }
  return 0;
}
