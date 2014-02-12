#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;
const int MAXN = 1120;

vector<int> prime;
bool is_prime[MAXN];
ll dp[MAXN + 1][20][300];

ll cur(int n, int k, int index){
  ll res = 0;
  if(n == 0 && k == 0) return 1;
  if(k == 0) return 0;
  if(n <= 0) return 0;
  if(dp[n][k][index] >= 0) return dp[n][k][index];

  for(int i = index; i < (int)prime.size(); i++){
    if(n + prime[i] < 0) break;
    res += cur(n - prime[i], k - 1, i + 1);
  }
  return dp[n][k][index] = res;
}

int main(int argc, char **argv){
  
  memset(is_prime, true, sizeof(is_prime));
  is_prime[0] = is_prime[1] = false;
  for(int i = 2; i <= MAXN; i++){
    if(is_prime[i]){
      prime.push_back(i);
      for(int j = 2 * i; j <= MAXN; j += i) is_prime[j] = false;
    }
  }
  int N, K;
  memset(dp, -1, sizeof(dp));
  while(cin >> N >> K, N | K){
    cout << cur(N, K, 0) << endl;
  }
  return 0;
}