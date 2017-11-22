#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 60
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define CNT(c,x) count(ALL(c),x)
#define dump(x)  cerr << #x << " = " << (x) << endl;
template<typename A, size_t N, typename T>
void FILL(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

using namespace std;

int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};

int main(){
  int n;
  cin >> n;
  vector<string> f(n + 2, string(n + 2, '#'));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      char c; cin >> c;
      f[i + 1][j + 1] = c;
    }
  }
  n += 2;

  int w[35][35];
  bool vis[35][35];
  memset(w, 0, sizeof(w));
  memset(vis, false, sizeof(vis));
  for(int j = 0; j < 2; j++){
    int i;
    if(j == 0) i = n + 1;
    else i = n * n - n - 2;
    if(f[i/n][i%n] == '#' || vis[i/n][i%n]) continue;
    queue<int> Q;
    Q.push(i);
    vis[i/n][i%n] = true;
  
    while(!Q.empty()){
      int y = Q.front() / n, x = Q.front() % n;
      Q.pop();
      for(int k = 0; k < 4; k++){
	int ny = y + dy[k], nx = x + dx[k];

	if(f[ny][nx] == '#'){
	  w[ny][nx]++;
	  continue;
	}

	if(vis[ny][nx]) continue;
	vis[ny][nx] = true;
	Q.push(ny * n + nx);
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < 35; i++)
    for(int j = 0; j < 35; j++)
      ans += w[i][j];
  cout << ans * 9 - 36 << endl;
  return 0;
}
