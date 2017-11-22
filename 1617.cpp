// Time-stamp: <Sun Feb 12 00:10:41 東京 (標準時) 2017>
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

int main(int argc, char **argv){
  string seed;
  string text;
  while(1){
    cin >> seed;
    if(seed == "THEEND") break;
    cin >> text;
    int H = text.size() / seed.size();
    int W = seed.size();
    vector<string> f(H, string(W, ' '));

    int cnt = 0;
    for(char c = 'A'; c <= 'Z'; c++){
      for(int i = 0; i < W; i++){
	if(seed[i] != c) continue;
	for(int y = 0; y < H; y++) f[y][i] = text[cnt * H + y];
	cnt++;
      }
    }
    for(int y = 0; y < H; y++) cout << f[y];
    cout << endl;
  }
  return 0;
}
