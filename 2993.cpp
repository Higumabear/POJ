// Time-stamp: <Thu Oct 27 23:43:26 東京 (標準時) 2016>
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

vector<string> parse(string s){
  for(int i = 0; i < s.size(); i++) 
    s[i] = s[i] == ',' ? ' ' : s[i];
  stringstream ss(s);
  ss >> s;
  vector<string> ret;
  while(ss >> s) ret.push_back(s);
  return ret;
}

int main(int argc, char **argv){
  string f[17];
  for(int i = 0; i < 17; i++){
    if(i % 2 == 0)
      f[i] = "+---+---+---+---+---+---+---+---+";
    else if(i % 4 == 1)
      f[i] = "|:::|...|:::|...|:::|...|:::|...|";
    else
      f[i] = "|...|:::|...|:::|...|:::|...|:::|";
  }
  string s;
  getline(cin, s);
  vector<string> white = parse(s);
  cin.ignore();
  getline(cin, s);
  vector<string> black = parse(s);

  for(int i = 0; i < black.size(); i++){
    if(black[i].size() == 3){
      int y = (int)(black[i][2] - '1');
      int x = (int)(black[i][1] - 'a');
      f[1 + 2 * y][2 + 4 * x] = tolower(black[i][0]);
    }else{
      int y = (int)(black[i][1] - '1');
      int x = (int)(black[i][0] - 'a');
      f[1 + 2 * y][2 + 4 * x] = 'p';      
    }
  }
  for(int i = 0; i < white.size(); i++){
    if(white[i].size() == 3){
      int y = (int)(white[i][2] - '1');
      int x = (int)(white[i][1] - 'a');
      f[1 + 2 * y][2 + 4 * x] = toupper(white[i][0]);
    }else{
      int y = (int)(white[i][1] - '1');
      int x = (int)(white[i][0] - 'a');
      f[1 + 2 * y][2 + 4 * x] = 'P';      
    }
  }


  for(int i = 16; i >= 0; i--)
    cout << f[i] << endl;
  return 0;
}
