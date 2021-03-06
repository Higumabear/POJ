// Time-stamp: <Mon Nov 28 18:12:27 東京 (標準時) 2016>
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

int x[200001], y[200001];
int main(int argc, char **argv){
  int N;
  while(scanf("%d", &N), N){
    for(int i = 0; i < N; i++)
      scanf("%d %d", &x[i], &y[i]);

    int Stan = 0, Ollie = 0;
    for(int i = 0; i < N; i++){
      if((x[i] > x[N / 2] && y[i] > y[N / 2]) ||
	 (x[i] < x[N / 2] && y[i] < y[N / 2])) Stan++;
      if((x[i] > x[N / 2] && y[i] < y[N / 2]) || 
	 (x[i] < x[N / 2] && y[i] > y[N / 2])) Ollie++;
    }
    printf("%d %d\n", Stan, Ollie);
  }
  return 0;
}
