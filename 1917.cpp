// Time-stamp: <Sun Jan 08 22:11:12 東京 (標準時) 2017>
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
  int N;
  cin >> N;
  cin.ignore();
  while(N--){
    string s, t;
    getline(cin, s);
    getline(cin, t);
    
    int idx = 0;
    string ss[5];
    for(int i = 0; i < s.length(); i++){
      if(s[i] == '<' || s[i] == '>') idx++;
      else ss[idx] += s[i];
    }
    cout << ss[0] << ss[1] << ss[2] << ss[3] << ss[4] << endl;
    for(int i = 0; i < t.length(); i++){
      if(t[i] == '.'){
	cout << ss[3] << ss[2] << ss[1] << ss[4] << endl;
	break;
      }else cout << t[i];
    }
  }
  return 0;
}
