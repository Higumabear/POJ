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

bool d[200][200][26];

int main(){
  int V;
  while(cin >> V, V){
    FILL(d, false);
    
    int u, v;
    string s;
    while(cin >> u >> v, u + v){
      cin >> s;
      u--, v--;
      for(int i = 0; i < s.size(); i++)
	d[u][v][s[i] - 'a'] = true;
    }
    for(int c = 0; c < 26; c++)
      for(int k = 0; k < V; k++)
	for(int i = 0; i < V; i++)
	  for(int j = 0; j < V; j++)
	    d[i][j][c] |= (d[i][k][c] & d[k][j][c]);

    while(cin >> u >> v, u + v){
      u--, v--;
      string ans;
      for(int c = 0; c < 26; c++)
	if(d[u][v][c]) ans += (char)('a' + c);

      if(ans.empty()) cout << '-' << endl;
      else cout << ans << endl;
    }
    cout << endl;
  }
  return 0;
}
