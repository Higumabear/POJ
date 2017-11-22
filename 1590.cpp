// Time-stamp: <Mon Feb 20 22:58:37 東京 (標準時) 2017>
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

map<char, char> mirror;

bool ispal(string s){
  string t(s);
  reverse(ALL(t));
  return t == s;
}

bool ismir(string s){
  int L = s.size();
  for(int i = 0; i <= L - i - 1; i++)
    if(!mirror.count(s[i]) || mirror[s[i]] != s[L - i - 1])
      return false;
  return true;
}

int main(int argc, char **argv){
  mirror['A'] = 'A';
  mirror['E'] = '3';
  mirror['H'] = 'H';
  mirror['I'] = 'I';
  mirror['J'] = 'L';
  mirror['L'] = 'J';
  mirror['M'] = 'M';
  mirror['O'] = 'O';
  mirror['S'] = '2';
  mirror['T'] = 'T';
  mirror['U'] = 'U';
  mirror['V'] = 'V';
  mirror['W'] = 'W';
  mirror['X'] = 'X';
  mirror['Y'] = 'Y';
  mirror['Z'] = '5';
  mirror['1'] = '1';
  mirror['2'] = 'S';
  mirror['3'] = 'E';
  mirror['5'] = 'Z';
  mirror['8'] = '8';
  
  string s;
  while(cin >> s){
    if(ismir(s) && ispal(s)){
      cout << s << " -- is a mirrored palindrome." << endl;
    }else if(ismir(s)){
      cout << s << " -- is a mirrored string." << endl;
    }else if(ispal(s)){
      cout << s << " -- is a regular palindrome." << endl;
    }else{
      cout << s << " -- is not a palindrome." << endl;
    }
    cout << endl;
  }
  return 0;
}
