// Time-stamp: <Fri Dec 23 16:13:23 東京 (標準時) 2016>
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

int cost[10100];
int main(int argc, char **argv){
  int V, ans = 0;
  scanf("%d", &V);
  for(int i = 0; i < V; i++){
    int c, num;
    scanf("%d %d", &c, &num);
    int dist = 0;
    for(int j = 0; j < num; j++){
      int pre; scanf("%d", &pre);
      dist = max(dist, cost[pre - 1]);
    }
    cost[i] = dist + c;
    ans = max(ans, cost[i]);
  }
  printf("%d\n", ans);
}
