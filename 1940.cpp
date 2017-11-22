// Time-stamp: <Tue Mar 07 22:06:57 東京 (標準時) 2017>
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

double x[1000000], y[1000000];

int main(int argc, char **argv){
  int N;
  while(scanf("%d", &N) != EOF){
    for(int i = 0; i < N; i++)
      scanf("%lf %lf", x + i, y + i);
    
    printf("%d ", N);
    double prevX = 0, prevY = 0;
    for(int i = 0; i < N; i++){
      if(i == 0){
	double X = 0, Y = 0;
	for(int j = 0; j < N; j++){
	  if(j % 2 == 0) X += x[j], Y += y[j];
	  else X -= x[j], Y -= y[j];
	}
	printf("%.6f %.6f ", X, Y);	
	prevX = X, prevY = Y;
      }
      else{
	prevX = 2.0 * x[i - 1] - prevX;
	prevY = 2.0 * y[i - 1] - prevY;
	printf("%.6f %.6f ", prevX, prevY);	
      }
    }
    printf("\n");
  }
  return 0;
}
