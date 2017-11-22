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

char s[100];
int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isleap(int x){
  if(x % 400 == 0) return true;
  if(x % 100 == 0) return false;
  return x % 4 == 0;
}

int days(int m, int d, int y){
  int c = 0;
  for(int i = 1999; i < y; i++) c += (isleap(i) ? 366 : 365);
  for(int p = 0; p < m - 1; p++){
    if(p == 1 && isleap(y)) c += 29;
    else c += mon[p];
  }
  return c + d;
}

int main(){
  int N;
  scanf("%d", &N);
  getchar();
  for(int n = 1; n <= N; n++){
    gets(s);
    int m, d, y, mm, dd;
    sscanf(s, "%d/%d/%d %d/%d", &m, &d, &y, &mm, &dd);
    //getchar();

    printf("%d ", n);
    if(m == mm && d == dd) printf("SAME DAY\n");
    else{
      int a = days(m, d, y);
      //dump(a);
      for(int t = y - 1; t <= y + 1; t++){
	if(mm == 2 && dd == 29 && !isleap(t)) continue;
	int b = days(mm, dd, t);
	//dump(b);
	int delta = abs(a - b);
	if(delta <= 7){
	  printf("%d/%d/%d IS %d %s %s\n",
		 mm, dd, t, delta,
		 (delta == 1 ? "DAY" : "DAYS"),
		 (a - b > 0 ? "PRIOR" : "AFTER"));
	  goto L1;
	}
      }
      puts("OUT OF RANGE");
    L1:;
    }
  }
  return 0;
}
