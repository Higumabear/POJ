// Time-stamp: <Thu Feb 23 22:34:49 東京 (標準時) 2017>
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

void split(char *s, int &score, string &str){
  int p = 0, i;
  for(i = 0; i < strlen(s); i++){
    if('0' <= s[i] && s[i] <= '9'){
      p *= 10;
      p += s[i] - '0';
    }else break;
  }
  str = string(s + i + 1);
  score = p;
  // if(strcmp(s + i + 1, "Li Ming") == 0){
  //   return 10 * p + 1;
  // }else{
  //   return 10 * p;
  // }
  return;
}

int main(int argc, char **argv){
  int N;
  scanf("%d\n", &N);
  char str[110];
  map<string, int> p;
  for(int i = 0; i < N; i++){
    gets(str);
    p[string(str)] = 0;
  }

  int M;
  scanf("%d\n", &M);
  for(int i = 0; i < M; i++){
    int lmp;
    for(int j = 0; j < N; j++){
      gets(str);
      int point;
      string s;
      split(str, point, s);
      p[s] += point;
      if(s == "Li Ming") lmp = p[s];
    }

    int ans = 1;
    map<string, int>::iterator it = p.begin();
    for(; it != p.end(); it++){
      //cout << it->first << " ";
      if(it->second > lmp) ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
