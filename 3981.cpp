// Time-stamp: <Tue Nov 01 21:59:56 東京 (標準時) 2016>
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
  char s[1005];
  char *p;
  while(gets(s)){
    p = strtok(s, " ");
   
    if(strcmp(p, "you") == 0) printf("we ");
    else printf("%s ", p);
    while(p != NULL){
      p = strtok(NULL, " ");
      if(p == NULL) break;
      if(strcmp(p, "you") == 0) printf("we ");
      else printf("%s ", p);
    }
    printf("\n");
  }
  return 0;
}
