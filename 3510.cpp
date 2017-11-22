// Time-stamp: <Thu Feb 16 21:13:58 東京 (標準時) 2017>
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

void strReplace(string &str, const string &from, const string &to){
  string::size_type pos = 0;
  while((pos = str.find(from, pos)) != string::npos){
    str.replace(pos, from.length(), to);
    pos += to.length();
  }
}

int main(int argc, char **argv){
  string s;
  while(getline(cin, s)){
    int idx = s.find("EOF");
    bool final = false;
    if(idx != string::npos){
      s = s.substr(0, idx);
      final = true;
    }
    // for(int i = 1; i < s.size(); i++){
    //   if(s[i - 1] == 'd' && s[)
    // }
    strReplace(s, "dd", "*p*");
    strReplace(s, "pink", "floyd");
    strReplace(s, "*p*", "p");
    //strReplace(s, "ei", "ie");//cのときなし
    for(int i = 1; i < s.size(); i++){
      if(s[i - 1] == 'e' && s[i] == 'i'){
	if(i == 1 || (2 <= i && s[i - 2] != 'c')){
	  s[i - 1] = 'i', s[i] = 'e'; i++;
	}
      }
    }

    for(unsigned char c = 0; c < 0xff; c++){
      if(('a' <= c && c <= 'z') || c == ' ') continue;
      string d; d += c;
      strReplace(s, d, "");
    }
    cout << s << endl;
    if(final) break;
  }
  return 0;
}
