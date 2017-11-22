#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> p[25];

int main(){
  int M, C;
  scanf("%d %d", &M, &C);

  int ans = 0, N = 0;
  for(int i = 0; i < M; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    if(a >= C) ans += b;
    else p[N++] = make_pair(a, b);
  }
  sort(p, p + N);

  int use[25];
  while(1){
    fill(use, use + 25, 0);
    int val = 0;
    for(int i = N - 1; i >= 0; i--){
      if(p[i].second <= 0 || val >= C) continue;
      int u  = min(p[i].second, (C - val) / p[i].first);
      if(u){
	use[i] += u;
	val += p[i].first * u;
      }
    }
    
    for(int i = 0; i < N; i++){
      if(p[i].second <= 0 || val >= C) continue;
      int u  = min(p[i].second - use[i],
		   (C - val + p[i].first - 1) / p[i].first);
      if(u){
	use[i] += u;
	val += p[i].first * u;
      }
    }
    if(val < C) break;

    int add = 1 << 30;
    for(int i = 0; i < N; i++) if(use[i] > 0)
      add = min(add, p[i].second / use[i]);
    
    ans += add;
    for(int i = 0; i < N; i++)
      if(use[i] > 0) p[i].second -= use[i] * add;
  }
  printf("%d\n", ans);
}
