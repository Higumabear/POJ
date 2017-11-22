// Time-stamp: <Sat Feb 04 23:52:29 東京 (標準時) 2017>
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

string s[9] = {
  " ", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"
};

int main(int argc, char **argv){
  map<char, int> group, press;
  for(int i =0; i < 9; i++){
    for(int j = 0; j < s[i].size(); j++){
      group[s[i][j]] = i;
      press[s[i][j]] = j + 1;
    }
  }
  int t;
  cin >> t;
  for(int k = 0; k < t; k++){
    int p, w;
    string str;
    cin >> p >> w; cin.ignore();
    getline(cin, str);

    int ans = 0;
    for(int j = 0; j < str.size(); j++){
      if(j == 0){
	ans += press[str[j]] * p;
      }else{
	int x = 0;
	if(group[str[j - 1]] == group[str[j]] && str[j] != ' ') x = 1;
	ans += press[str[j]] * p + x * w;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
