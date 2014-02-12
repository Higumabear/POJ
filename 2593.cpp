#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1 << 28;

int l[100001];
int r[100001];
int dp_l[100001];
int dp_r[100001];
int a[100000];

int main(int argc, char **argv){
  int N;
  while(scanf("%d", &N), N){
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);

    int lmax = l[0] = dp_l[0] = a[0];
    for(int i = 1; i < N; i++){
      l[i] = a[i] + max(l[i - 1], 0);
      if(lmax < l[i])
	lmax = l[i];
      dp_l[i] = lmax;
    }

    int rmax = r[N - 1] = dp_r[N - 1] = a[N - 1];
    for(int i = N - 2; i >= 0; i--){
      r[i] = a[i] + max(r[i + 1], 0);
      if(rmax < r[i])
	rmax = r[i];
      dp_r[i] = rmax;
    }

    int ans = -INF;
    for(int i = 0; i < N - 1; i++)
      ans = max(ans, dp_l[i] + dp_r[i + 1]);

    cout << ans << endl;
  }
  return 0;
}