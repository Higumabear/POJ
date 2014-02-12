#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <cstring>

using namespace std;

bool dp[10001][100];
int a[10000];

int N, K;

int abs(int a){return a > 0 ? a : -a;};
void dfs(int i, int m){
  m %= K;
  if(dp[i][m]) return;
  
  dp[i][m] = true;
  if(i == N) return;
  //cout << i << " " << m << endl;
  dfs(i + 1, m + a[i] + 10000 * K);
  dfs(i + 1, m - a[i] + 10000 * K);
}

int main(int argc, char **argv){
  memset(dp, false, sizeof(dp));
  cin >> N >> K;
  for(int i = 0; i < N; i++)
    cin >> a[i];

  dfs(0, 0);
  if(dp[N][0]) cout << "Divisible" << endl;
  else cout << "Not divisible" << endl;
  return 0;
}