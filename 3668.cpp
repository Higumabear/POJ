#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
const int INF = (1 << 31) - 1;


int x[201], y[201];
int gcd(int a, int b){return b == 0 ? a : gcd(b, a % b);}
int main(int argc, char **argv){
  int N;
  scanf("%d", &N);
  for(int i = 0; i < N; i++)
    scanf("%d %d", x + i, y + i);

  set<pair<int, int> > q;
  for(int i = 0; i < N; i++){
    for(int j = i + 1; j < N; j++){
      int dx = x[j] - x[i];
      int dy = y[j] - y[i];
      if(dx < 0) dx = -dx, dy = -dy;
      if(dx == 0) dy = 1;
      if(dy == 0) dx = 1;

      int g = gcd(dx, abs(dy));
      //printf("(%d %d) -> (%d %d) : %d %d\n", x[i], y[i], x[j], y[j], dx / g, dy / g);
      q.insert(make_pair(dx / g, dy / g));
    }
  }
  printf("%d\n", q.size());
}
