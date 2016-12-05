// Time-stamp: <Fri Oct 07 23:32:33 東京 (標準時) 2016>
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
  int a[5];
  int b[5];
  while(scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4]), 
	a[0] | a[1] | a[2] | a[3] | a[4]){
    
    int cnt = INF;
    for(int i = 0; i <= a[0]; i++)
      for(int j = 0; j <= a[1]; j++)
	for(int k = 0; k <= a[2]; k++){
	  int sum = i * 25 + j * 10 + k * 5;
	  if(sum <= a[4] && a[4] - sum <= a[3]){
	    int use = i + j + k + a[4] - sum;
	    if(use < cnt){
	      cnt = use;
	      b[0] = i, b[1] = j, b[2] = k, b[3] = a[4] - sum;
	    }
	  }
	}
    if(cnt == INF)
      printf("Cannot dispense the desired amount.\n");
    else
      printf("Dispense %d quarters, %d dimes, %d nickels, and %d pennies.\n",
	     b[0], b[1], b[2], b[3]);
  }
  return 0;
}
