// Time-stamp: <Wed Dec 14 22:20:33 東京 (標準時) 2016>
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

bool vowel(char c){
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y'; 
}
int syllable(string s){
  int ret = 0;
  char prev = '@';
  for(int i = 0; i < s.size(); i++){
    if(!vowel(prev) && vowel(s[i])) ret++;
    prev = s[i];
  }
  return ret;
}

int cnt(string s){
  for(int i = 0; i < s.size(); i++)
    if(s[i] == '$') s[i] = ' ';
  stringstream ss(s);
  int ret = 0;
  string t;
  while(ss >> t) ret += syllable(t);
  return ret;
}

int main(int argc, char **argv){
  string s;
  while(getline(cin, s)){
    if(s == "e/o/i") break;
    for(int i = 0; i < s.size(); i++)
      if(s[i] == ' ') s[i] = '$';
      else if(s[i] == '/') s[i] = ' ';
    stringstream ss(s);
    string s1, s2, s3;
    ss >> s1 >> s2 >> s3;
    if(cnt(s1) != 5) cout << 1 << endl;
    else if(cnt(s2) != 7) cout << 2 << endl;
    else if(cnt(s3) != 5) cout << 3 << endl;
    else cout << "Y" << endl;
  }
  return 0;
}
