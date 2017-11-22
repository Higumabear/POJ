// Time-stamp: <Wed Feb 08 22:47:09 東京 (標準時) 2017>
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
  int N;
  while(scanf("%d", &N), N){
    vector<int> v(N);
    for(int i = 0; i < N; i++)
      scanf("%d", &v[i]);

    int denom = N * (N - 1) / 2;
    int nume = 0;
    for(int i = 0; i < N; i++)
      for(int j = i + 1; j < N; j++)
	if(__gcd(v[i], v[j]) == 1) nume++;
    
    if(nume == 0){
      printf("No estimate for this data set.\n");
    }else{
      printf("%.6f\n", sqrt((double)N * (N - 1) * 0.5 / nume * 6.0));
    }
  }
  return 0;
}
