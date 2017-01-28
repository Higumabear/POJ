// Time-stamp: <Tue Jan 17 22:45:23 東京 (標準時) 2017>
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

char s[1001];
bool f[1010][1010];
int dp[1010][1010];
int main(int argc, char **argv){
  int t;
  scanf("%d", &t);
  while(t--){
    int H, W;
    scanf("%d %d", &H, &W);
    for(int i = 0; i < H; i++){
      scanf("%s", &s);
      for(int j = 0; j < W; j++) 
	f[i][j] = (s[j] == '.');
    }
    dp[0][0] = 1;
    for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++){
	if(i | j) dp[i][j] = 0;
	if(!f[i][j]) continue;
	if(i - 1 >= 0) dp[i][j] += dp[i - 1][j];
	if(j - 1 >= 0) dp[i][j] += dp[i][j - 1];
      }
    }
    printf("Existuje %d ruznych cest.\n", dp[H - 1][W - 1]);
  }
  return 0;
}
