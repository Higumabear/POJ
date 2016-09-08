#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <numeric>
#include <time.h>
#include <algorithm>

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

char al[] = "abcdefghijklmnopqrstuvwxyz";

int num, cnt;
vector<int> d;
inline void rec(int s, int idx, int use){
  if(idx == 28) return;
  //if(use + 27 - idx < num) return;
  if(use == num){
    d[cnt++] = s;
    return;
  }
  rec(27 * s + idx, idx + 1, use + 1);
  rec(s, idx + 1, use);
  return;
}
int main(int argc, char **argv){
  d.assign(100000, INF);
  for(num = 1; num <= 5; num++) rec(0, 1, 0);

  char c[10];
  while(scanf("%s", c) != -1){
    int L = strlen(c);

    int b = 0;
    bool check = true;
    for(int i = 0; i < L; i++){
      if(i && c[i - 1] >= c[i]) check = false;
      b = 27 * b + (int)(c[i] - '`');
    }
    //cout << b << " " << d[b] << endl;
    int f = lower_bound(ALL(d), b) - d.begin();
    //cout << b << " " << f + 1 << endl;
    printf("%d\n", check ? f + 1 : 0);
  } 
}