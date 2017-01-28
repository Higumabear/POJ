// Time-stamp: <Sun Jan 15 22:25:43 東京 (標準時) 2017>
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

char f[9][9];
int main(int argc, char **argv){
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++){
    for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
	cin >> f[i][j];
      }
    }

    for(int q = 0; q < 9 * 9; q++){
      for(int i = 0; i < 9; i++){
	for(int j = 0; j < 9; j++){
	  if(f[i][j] != '0') continue;
	  int ans = 0, sum = 0;
	  for(int c = 0; c < 9; c++){
	    ans += f[i][c] == '0';
	    sum += (f[i][c] - '0');
	  }
	  if(ans == 1){
	    f[i][j] = (char)(45 - sum + '0');
	    continue;
	  }
	
	  ans = 0, sum = 0;
	  for(int c = 0; c < 9; c++){
	    ans += f[c][j] == '0';
	    sum += (f[c][j] - '0');
	  }
	  if(ans == 1){
	    f[i][j] = (char)(45 - sum + '0');
	    continue;
	  }

	  ans = 0, sum = 0;
	  for(int y = 0; y < 3; y++){
	    for(int x = 0; x < 3; x++){
	      ans += f[i / 3 * 3 + y][j / 3 * 3 + x] == '0';
	      sum += (f[i / 3 * 3 + y][j / 3 * 3 + x] - '0');
	    }
	  }
	  if(ans == 1){
	    f[i][j] = (char)(45 - sum + '0');
	    continue;
	  }
	}
      }
    }
    cout << "Scenario #" << t << ":\n";
    for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
	cout << f[i][j];
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
