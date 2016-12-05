// Time-stamp: <Wed Nov 30 21:08:48 東京 (標準時) 2016>
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
  string s, t;
  while(getline(cin, s)){
    // sort(ALL(s));
    // sort(ALL(t));
    // int j = 0;
    // string ans;
    // for(int i = 0; i < s.size(); i++){
    //   string::iterator it = find(t.begin() + j, t.end(), s[i]);
    //   if(it != t.end()){
    // 	j = it - t.begin();
    // 	ans += t[j];
    // 	j++;
    //   }
    // }
    // cout << ans << endl;
    getline(cin, t);
    string ans;
    map<char, int> a, b;
    for(char c = 'a'; c <= 'z'; c++) a[c] = b[c] = 0;
    for(int i = 0; i < s.size(); i++) a[s[i]]++;
    for(int i = 0; i < t.size(); i++) b[t[i]]++;
    for(char c = 'a'; c <= 'z'; c++){
      ans += string(min(a[c], b[c]), c);
    }
    cout << ans << endl;
  }
  return 0;
}
