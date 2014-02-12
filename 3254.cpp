#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

int M, N; 
int field[12][12];
int dp[12][12][1 << 12];
const int MOD = 100000000;

int solve(int pos, int bit){
  int y = pos / N, x = pos % N;
  if(x == 0 && y == M) return 1;
  int res = 0;
  if(dp[y][x][bit] >= 0) return dp[y][x][bit];
  if(field[y][x] == 0){
    res = solve(pos + 1, (bit << 1) & ((1 << N) - 1));
  }else{
    int tmp = bit;
    res = solve(pos + 1, (tmp << 1) & ((1 << N) - 1));
    if(!(tmp & (1 << (N - 1)) || ((x != 0) && (tmp & 1)))){
      tmp = ((bit << 1) & ((1 << N) - 1)) | 1;
      res += solve(pos + 1, tmp);
    }
    res %= MOD;
  }
  return dp[y][x][bit] = res;
}

int main(int argc, char **argv){
  cin >> M >> N;
  for(int i = 0; i < M; i++)
    for(int j = 0; j < N; j++)
      cin >> field[i][j];

  memset(dp, -1, sizeof(dp));
  cout << solve(0,0) << endl;
  return 0;
}