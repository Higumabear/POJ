// Time-stamp: <Fri Jul 28 02:07:47 東京 (標準時) 2017>
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

char s[1100];

int main(int argc, char **argv){
  int n, t;
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    int in[26] = {0};
    int out[26] = {0};
    bool appear[26] = {false};
    bool adj[26][26] = {false};
    for(int i = 0; i < n; i++){
      scanf("%s", &s);
      int l = strlen(s);
      out[s[0] - 'a']++;
      in[s[l - 1] - 'a']++;
      adj[s[0] - 'a'][s[l - 1] - 'a'] = true;
      appear[s[0] - 'a'] = appear[s[l - 1] - 'a'] = true;
    }

    int a = 0;
    bool flag = true;
    for(int i = 0; i < 26; i++){
      a += (in[i] != out[i]);
      flag &= (abs(out[i] - in[i]) < 2);
      adj[i][i] = true;
    }
    for(int k = 0; k < 26; k++)
      for(int i = 0; i < 26; i++)
	for(int j = 0; j < 26; j++)
	  adj[i][j] |= (adj[i][k] && adj[k][j]);

    for(int i = 0; i < 26; i++)
      for(int j = 0; j < 26; j++)
	if(appear[i] && appear[j])
	  flag &= (adj[i][j] || adj[j][i]);
    printf("%s\n", flag && a <= 2 ? "Ordering is possible." : "The door cannot be opened.");
  }
  return 0;
}
