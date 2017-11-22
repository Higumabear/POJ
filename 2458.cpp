// Time-stamp: <Fri Aug 25 21:00:29 東京 (標準時) 2017>
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

string f;

bool m[5][5];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int dfs(int y, int x){
  int v = 1;
  m[y][x] = false;
  for(int i = 0; i < 4; i++){
    int ny = y + dy[i], nx = x + dx[i];
    if(0 <= nx && nx < 5 && 0 <= ny && ny < 5 && m[ny][nx])
      v += dfs(ny, nx);
  }
  return v;
}

bool c(vector<int> &a){
  memset(m, false, sizeof(m));
  for(int i = 0; i < 7; i++)
    m[a[i] / 5][a[i] % 5] = true;
  return dfs(a[0] / 5, a[0] % 5) == 7;
}

int main(int argc, char **argv){
  string s;
  for(int i = 0; i < 5; i++){
    cin >> s;
    f += s;
  }
  int L = 25;

  
  vector<int> a(7), b(7, 0);
  int ans = 0LL;
  for( a[0] = 0; a[0] < L; a[0]++){
    b[0] = (f[a[0]] == 'J');
    for( a[1] = a[0]+1; a[1] < L; a[1]++){
      b[1] = (f[a[1]] == 'J');
      for( a[2] = a[1]+1; a[2] < L; a[2]++){
	b[2] = (f[a[2]] == 'J');
	for( a[3] = a[2]+1; a[3] < L; a[3]++){
	  b[3] = (f[a[3]] == 'J');
	  if(b[0] + b[1] + b[2] + b[3] == 0) continue;
	  for( a[4] = a[3]+1; a[4] < L; a[4]++){
	    b[4] = (f[a[4]] == 'J');
	    for( a[5] = a[4]+1; a[5] < L; a[5]++){
	      b[5] = (f[a[5]] == 'J');
	      for( a[6] = a[5]+1; a[6] < L; a[6]++){
		b[6] = (f[a[6]] == 'J');
		int J = b[0] + b[1] + b[2] + b[3] + b[4] + b[5] + b[6];
		if(J <= 3) continue;
		ans += c(a);
		// if(c(a)){
		//   ans++;
		//   for(int i = 0; i < 7; i++)
		//     cout << a[i] / 5 << " " << a[i] % 5 << endl;
		//   cout << "-------------" << endl;
		// }
	      }
	    }
	  }
	}
      }
    }
  }
  cout << ans << endl;
  return 0;
}
