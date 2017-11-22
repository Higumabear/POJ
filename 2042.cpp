// Time-stamp: <Sun Feb 19 23:29:07 東京 (標準時) 2017>
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
  vector<bool> rem(1 << 16, false);
  for(int i = 1; i * i <= 1 << 15; i++)
    rem[i * i] = true;

  int N;
  while(cin >> N, N){
    int cnt = 0;
    int SQ = sqrt(N + EPS);
    if(SQ * SQ == N) cnt++;
    for(int i = 1; i <= SQ; i++){
      int ii = i * i;
      int remi = N - ii;
      if(ii > remi) break;
      cnt += rem[remi];
      for(int j = i; j <= SQ; j++){
	int jj = j * j;
	int remj = N - ii - jj;
	if(jj > remj) break;
	cnt += rem[remj];
	for(int k = j; k <= SQ; k++){
	  int kk = k * k;
	  int remk = N - ii - jj - kk;
	  if(kk > remk) break;
	  cnt += rem[remk];
	}
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
