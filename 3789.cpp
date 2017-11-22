// Time-stamp: <Mon Feb 13 21:51:25 東京 (標準時) 2017>
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
  int t;
  scanf("%d", &t);
  for(int k = 0; k < t; k++){
    int d[3];
    scanf("%d:%d:%d", &d[0], &d[1], &d[2]);
    
    bool f[3][6];
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 6; j++)
	f[i][j] = (d[i] >> j & 1);
    
    printf("%d ", k + 1);
    for(int j = 5; j >= 0; j--)    
      for(int i = 0; i < 3; i++)
	printf("%d", f[i][j]);
    printf(" ");
    for(int i = 0; i < 3; i++)
      for(int j = 5; j >= 0; j--)
	printf("%d", f[i][j]);
    printf("\n");
  }
  return 0;
}
