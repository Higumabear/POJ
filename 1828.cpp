#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

struct pos{
  int x, y;
  bool operator<(const pos& r)const{
    if(x == r.x) return y < r.y;
    else return x < r.x;
  }
};

int main(int argc, char **argv){
  int N;
  while(scanf("%d", &N), N != 0){
    vector<struct pos> monkey;
    int x, y;
    for(int i = 0; i < N; i++){
      scanf("%d %d", &x, &y);
      pos t;
      t.x = x; t.y = y;
      monkey.push_back(t);
    }
    sort(monkey.begin(), monkey.end());

    int ans = 1;
    int maxy = monkey[N - 1].y;
    for(int i = N - 2; i >= 0; i--)
      if(monkey[i].y > maxy){
	maxy = monkey[i].y;
	ans++;
      }
    printf("%d\n", ans);
  }
  return 0;
}