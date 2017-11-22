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

void head(int &y, int &x, int d){
  switch(d){
  case 0:
    y += 10; break;
  case 1:
    x -= 10; break;
  case 2:
    y -= 10; break;
  case 3:
    x += 10; break;
  }
  return;
}

int main(){
  string s;
  while(cin >> s){
    cout << 300 << " " << 420 << " moveto" << endl;
    cout << 310 << " " << 420 << " lineto" << endl;

    int y = 310, x = 420, d = 0;
    for(int i = 0; i < s.size(); i++){
      if(s[i] == 'V') d = (d + 3) % 4;
      else d = (d + 1) % 4;
      head(y, x, d);
      cout << y << " " << x << " lineto" << endl;
    }
    cout << "stroke" << endl << "showpage" << endl;
  }
  return 0;
}
