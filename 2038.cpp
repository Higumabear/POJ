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

int p[100][0xff];

bool sign(int x){ return x > 0; }

int main(){
  int N;
  while(cin >> N, N){
    string s;
    for(int i = 0; i < N; i++){
      cin >> s;
      for(int k = 0; k < 5; k++) p[i][s[k]] = k;
    }
    string t("ABCDE");

    int ans = INF;
    string ans_s;
    do{
      int q[0xff];
      for(int k = 0; k < 5; k++) q[t[k]] = k;

      int tmp = 0;
      for(int i = 0; i < N; i++)
	for(char a = 'A'; a <= 'E'; a++)
	  for(char b = a + 1; b <= 'E'; b++)
	    if(sign(p[i][a] - p[i][b])
	       != sign(q[a] - q[b])) tmp++;

      if(tmp < ans){
	ans = tmp;
	ans_s = t;
      }
    }while(next_permutation(ALL(t)));
    cout << ans_s << " is the median ranking with value "
	 << ans << "." << endl;
  }
  return 0;
}
