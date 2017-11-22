#include <string>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100001;

long long sum[MAXN];

struct cow{
  int w, s;
  bool operator<(cow &r)const{
    return w + s < r.w + r.s;
  }
};

cow c[MAXN];

int main(){
  int N;
  long long W = 0;
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%d %d", &c[i].w, &c[i].s);
    W += c[i].w;
  }

  sort(c, c + N);
  reverse(c, c + N);
 
  long long ans = -(1LL << 40);
  for(int i = 0; i < N; i++){
    W -= c[i].w;
    ans = max(ans, W - c[i].s);
  }
  
  cout << ans << endl;
}
