// Time-stamp: <Tue Mar 14 22:26:52 東京 (標準時) 2017>
#include <cstdio>

using namespace std;

int main(int argc, char **argv){
  int N, M, a;
  static bool f[10001][1000];
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%d", &M);
    for(int j = 0; j < M; j++){
      scanf("%d", &a);
      f[a][i] = true;
    }
  }
  int Q, s, t;
  scanf("%d", &Q);
  while(Q--){
    scanf("%d %d", &s, &t);
    bool ok = false;
    for(int j = 0; j < N; j++){
      if(f[s][j] && f[t][j]){
	ok = true;
	break;
      }
    }
    puts(ok ? "Yes" : "No");
  }
  return 0;
}
