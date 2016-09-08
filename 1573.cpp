#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 61
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;
inline int s2i(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string i2s(T x) {ostringstream sout;sout<<x;return sout.str();}
template<typename A, size_t N, typename T> inline void FILL(A (&array)[N], const T &val){ std::fill( (T*)array, (T*)(array+N), val );}
const double PI  = acos(-1.0);

int H, W, E;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
bool inside(int y, int x){
  return 0 <= y && y < H && 0 <= x && x < W;
}

int main(int argc, char **argv){
  map<char, int> idx;
  idx['N'] = 0, idx['E'] = 1, idx['S'] = 2, idx['W'] = 3;
  while(cin >> H >> W >> E, H + W + E != 0){
    vector<string> f;
    for(int i = 0; i < H; i++) {
      string s; 
      cin >> s; 
      f.push_back(s);
    }
    vector<vector<int> > cnt(H, vector<int>(W, 0));

    int step = 0;
    int y = 0, x = E - 1;
    while(inside(y, x) && cnt[y][x] == 0){
      cnt[y][x] = ++step;
      int dir = idx[f[y][x]];
      y = y + dy[dir], x = x + dx[dir];
    }

    if(!inside(y, x))
      printf("%d step(s) to exit\n", step);
    else
      printf("%d step(s) before a loop of %d step(s)\n", 
	     cnt[y][x] - 1, step - cnt[y][x] + 1);
  }
  return 0;
}