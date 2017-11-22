// Time-stamp: <Sat Feb 11 01:39:19 東京 (標準時) 2017>
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

char f[4][4];
int win(char c){
  int cnt = 0;
  for(int i = 0; i < 3; i++){
    if(f[0][i] == c && f[1][i] == c && f[2][i] == c) cnt++;
    if(f[i][0] == c && f[i][1] == c && f[i][2] == c) cnt++;
  }
  if(f[0][0] == c && f[1][1] == c && f[2][2] == c) cnt++;
  if(f[0][2] == c && f[1][1] == c && f[2][0] == c) cnt++;
  return cnt;
}
int main(int argc, char **argv){
  int T;
  cin >> T;
  while(T--){
    char c;
    int  X = 0, O = 0;
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
	cin >> c;
	f[i][j] = c;
	if(c == 'X') X++;
	if(c == 'O') O++;
      }
    }
    if(win('X') > 2 || win('O') > 1){
      cout << "no" << endl;
      continue;      
    }
    if(X == O || X - O == 1){
      if(win('X') && win('O')){
	cout << "no" << endl;
	continue;
      }
      if(win('X') && X - O != 1){
	cout << "no" << endl;
	continue;
      }
      if(win('O') && X != O){
	cout << "no" << endl;
	continue;
      }
      cout << "yes" << endl;
    }else{
      cout << "no" << endl;
    }
  }
  return 0;
}
