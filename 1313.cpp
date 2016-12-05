// Time-stamp: <Sat Sep 10 03:28:42 東京 (標準時) 2016>
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
  int n;
  while(cin >> n, n){
    int sheet = (n + 3) / 4;
      cout << "Printing order for " << n << " pages:" << endl;
    for(int i = 1; i <= sheet; i++){
      int fr = 2 * i - 1;
      int bl = 2 * i;

      int fl = sheet * 4 + 1 - fr;
      int br = sheet * 4 + 1 - bl;
      
      cout << "Sheet " << i << ", front: ";
      if(fl > n) cout << "Blank, ";
      else cout << fl << ", ";
      cout << fr << endl;

      if(bl <= n){
	cout << "Sheet " << i << ", back : ";
	cout << bl << ", ";
	if(br > n) cout << "Blank";
	else cout << br;
	cout << endl;
      }
    }
  }
  return 0;
}
