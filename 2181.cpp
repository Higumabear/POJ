#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;
const int INF = 1 << 28;
int dp[150001];

int main(int argc, char **argv){
  int P; scanf("%d", &P);
  bool ascend = false;
  int prev = 0;
  int ans = 0;
  for(int i = 0; i < P; i++){
    int t;
    scanf("%d", &t);
    if(t > prev){
      if(!ascend) ans -= prev;
      ascend = true;
    }
    else{
      if(ascend) ans += prev;
      ascend = false;
    }
    prev = t;
  }
  printf("%d\n", (ascend ? ans + prev : ans));
  return 0;
}