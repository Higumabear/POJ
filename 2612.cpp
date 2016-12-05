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

using namespace std;

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 61
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;
inline int s2i(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string i2s(T x) {ostringstream sout;sout<<x;return sout.str();}
const double PI  = acos(-1.0);

int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main(){
  int n; cin >> n;
  vector<vector<bool>> mine(n, vector<bool>(n ,false)),
    ma(n, vector<bool>(n, false));
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
      char c;  cin >> c;
      mine[i][j] = c == '*';
    }
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
      char c;  cin >> c;
      ma[i][j] = c == 'x';
    }

  bool flag = false;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      if(ma[i][j] && mine[i][j]) flag = true;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      int cnt = 0;
      if(flag && mine[i][j]) cout << '*';
      else if(ma[i][j]){
	for(int k = 0; k < 8; k++){
	  int ny = i + dy[k], nx = j + dx[k];
	  if(0 <= nx && nx < n && 0 <= ny && ny < n && mine[ny][nx]) cnt++;
	}
	cout << cnt;
      }else{
	cout << '.';
      }
    }
    cout << endl;
  }

  return 0;
}
