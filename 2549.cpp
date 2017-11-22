#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

int d[1001];
struct s{
  int v, x, y;
  bool operator<(const s &r)const{
    return v < r.v;
  }
}sum[1000000], dif[1000000];

int main(){
  int N;
  while(scanf("%d", &N), N){
    fill(d, d + 1001, 0);
    for(int i = 0; i < N; i++)
      scanf("%d", d + i);
    
    int idx = 0;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
	if(i == j) continue;
	sum[idx].x = dif[idx].x = i;
	sum[idx].y = dif[idx].y = j;
	sum[idx].v = d[i] + d[j];
	dif[idx].v = d[i] - d[j];
	idx++;
      }
    }
    int NN = N * N - N;
    sort(sum, sum + NN);
    sort(dif, dif + NN);

    int j = 0, ans = -(1 << 30);
    for(int i = 0; i < NN; i++){
      while(sum[i].v > dif[j].v && j < NN) j++;
      if(sum[i].v == dif[j].v){
	if(sum[i].x != dif[j].x && sum[i].x != dif[j].y && 
	   sum[i].y != dif[j].x && sum[i].y != dif[j].y)
	  ans = max(ans, sum[i].v + d[dif[j].y]);
	//j++;
      }
    }
    if(ans == -(1 << 30))
      printf("no solution\n");
    else
      printf("%d\n", ans);
  }
}
