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

void rec(int sum){
  cout << "{";
  if(!sum){
    cout << "}";
    return;
  }
  for(int i = 0; i < sum; i++){
    rec(i);
    if(i != sum - 1) cout << ",";
  }
  cout << "}";
}

int main(){
  int T;
  cin >> T;
  cin.ignore();
  while(T--){
    string s, t;
    getline(cin, s);
    getline(cin, t);

    int a = 0, b = 0;
    for(int i = s.size() - 1; i >= 0; i--){
      if(s[i] != '}') break;
      a++;
    }
    for(int i = t.size() - 1; i >= 0; i--){
      if(t[i] != '}') break;
      b++;
    }
    int sum = a + b - 2;
    rec(sum);
    cout << endl;
  }
  return 0;
}
