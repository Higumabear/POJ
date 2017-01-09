// Time-stamp: <Wed Dec 21 22:54:23 東京 (標準時) 2016>
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

// int desc_sort(int x){
//   int d[4];
//   d[0] = x % 10;
//   d[1] = (x % 100) / 10;
//   d[2] = (x % 1000) / 100;
//   d[3] = x / 1000;
//   sort(d, d + 4);
//   if(x < 10) rotate(d, d + 3, d + 4);
//   else if(x < 100) rotate(d, d + 2, d + 4);
//   else if(x < 1000) rotate(d, d + 1, d + 4);
//   return d[0] + 10 * d[1] + 100 * d[2] + 1000 * d[3];
// }
// int asc_sort(int x){
//   int d[4];
//   d[0] = x % 10;
//   d[1] = (x % 100) / 10;
//   d[2] = (x % 1000) / 100;
//   d[3] = x / 1000;
//   sort(d, d + 4);
//   return d[3] + 10 * d[2] + 100 * d[1] + 1000 * d[0];
// }

int asc(int x){
  stringstream tt;
  tt << x;
  string s; tt >> s;
  sort(ALL(s));
  stringstream ss(s);
  ss >> x;
  return x;
}
int desc(int x){
  stringstream tt;
  tt << x;
  string s; tt >> s;
  sort(s.rbegin(), s.rend());
  stringstream ss(s);
  ss >> x;
  return x;
}

int main(int argc, char **argv){
  string t;
  while(cin >> t){
  // for(int a = 1000; a < 10000; a++){
  //   stringstream tt; tt << a;
  //   string t; tt >> t;
    if(t == "-1") break;
    printf("N=%s:\n", t.c_str());
    stringstream ss(t);
    int x; ss >> x;
    if(asc(x) == desc(x) || t.size() != 4){
      puts("No!!");
      continue;
    }
    int y;
    for(int i = 1; ; i++){
      y = desc(x) - asc(x);
      printf("%d-%d=%d\n", desc(x), asc(x), y);
      x = y;
	
      if(y == 0 || y == 6174){
	printf("Ok!! %d times\n", i);
	break;
      }
    }
  }
  return 0;
}
