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

int num[0xffff];

struct bigr{
  int occ, idx;
  const bool operator<(bigr &r)const{
    if(occ == r.occ) return idx < r.idx;
    else return occ > r.occ;
  }
};

int main(){
  int T;
  while(cin >> T, T){
    FILL(num, 0);
    cin.ignore();

    string s;
    for(int i = 0; i < T; i++){
      string t; getline(cin, t);
      s += t;
    }

    int C = 0;
    for(int i = 0; i < s.size() - 1; i++){
      int x = (int)(s[i] * 0xff + s[i + 1]);
      num[x]++;
      C++;
    }
  
    vector<bigr> p;  
    for(int i = 0; i < 0xffff; i++){
      bigr r;
      r.occ = num[i];
      r.idx = i;
      p.push_back(r);
    }

    sort(ALL(p));

    for(int i = 0; i < 5; i++)
      printf("%c%c %d %.6lf\n",
	     (char)(p[i].idx / 255), 
	     (char)(p[i].idx % 255), 
	     p[i].occ, p[i].occ * 1.0 / C);
    puts("");
  }
  return 0;
}
