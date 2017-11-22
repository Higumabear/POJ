#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

int h[100010];
int R[100010], L[100010];
int cumd[100010];

int main(){
  int N;
  while(scanf("%d", &N), N != -1){
    for(int i = 0; i < N; i++){
      int x;
      scanf("%d %d", &x, h + i);
      cumd[i + 1] = x + cumd[i];
    }

    stack<int> S;
    for(int i = 0; i < N; i++){
      while(S.size() && h[S.top()] >= h[i]) S.pop();
      L[i] = S.size() ? S.top() + 1 : 0;
      S.push(i);
    }
    S = stack<int>();
    for(int i = N - 1; i >= 0; i--){
      while(S.size() && h[S.top()] >= h[i]) S.pop();
      R[i] = S.size() ? S.top() : N;
      S.push(i);
    }

    long long ans = 0;
    for(int i = 0; i < N; i++)
      ans = max(ans, (long long)h[i] * (cumd[R[i]] - cumd[L[i]]));
    printf("%lld\n", ans);
  }
}
