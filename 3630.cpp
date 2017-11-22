// Time-stamp: <Fri Feb 10 23:35:13 東京 (標準時) 2017>
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
  int T;
  scanf("%d\n", &T);
  while(T--){
    int N;
    scanf("%d\n", &N);
    vector<string> str(N);
    for(int i = 0; i < N; i++){
      char s[10010];
      gets(s);
      str[i] = string(s);
    }
    sort(ALL(str));
    bool check = true;
    for(int i = 0; i < N - 1; i++){
      if(str[i + 1].find(str[i]) != string::npos){
	check = false;
	break;
      }
    }
    printf("%s\n", check ? "YES" : "NO");
  }
  return 0;
}
