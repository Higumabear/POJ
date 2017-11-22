#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

bool d[100][100];

int main(int argc, char **argv){
  int T;
  cin >> T;
  while(T--){
    int N, M, s, t;
    cin >> N >> M;
    memset(d, false, sizeof(d));
    for(int i = 0; i < N; i++) d[i][i] = true;
    for(int i = 0; i < M; i++){
      cin >> s >> t; s--, t--;
      d[t][s] = true;
    }
    for(int k = 0; k < N; k++)
      for(int i = 0; i < N; i++)
	for(int j = 0; j < N; j++)
	  d[i][j] |= (d[i][k] && d[k][j]);

    int ans = 0;
    for(int i = 0; i < N; i++){
      int cnt1 = 0, cnt2 = 0;
      for(int j = 0; j < N; j++){
	cnt1 += d[i][j];
	cnt2 += d[j][i];
      }
      ans += (cnt1 > (N + 1) / 2);
      ans += (cnt2 > (N + 1) / 2);
    }
    cout << ans << endl;
  }
}
