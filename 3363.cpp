#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;


bool f[101][101], t[101][101];

int main(){
  int n, m, r, c;
  while(cin >> n >> m >> r >> c, n){
    memset(f, false, sizeof(f));
    memset(t, false, sizeof(t));
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
	char c; cin >> c;
	f[i][j] = c == '1';
      }
    }
    int cnt = 0;
    for(int i = 0; i <= n - r; i++){
      for(int j = 0; j <= m - c; j++){
	if(f[i][j] == t[i][j]) continue;
	cnt++;
	for(int y = 0; y < r; y++)
	  for(int x = 0; x < c; x++)
	    t[i + y][j + x] = !t[i + y][j + x];
      }
    }
    bool same = true;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
	if(f[i][j] != t[i][j]) same = false;
    cout << (same ? cnt : -1) << endl;
  }
}