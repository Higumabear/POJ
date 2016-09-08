// Time-stamp: <Wed Sep 07 23:04:58 東京 (標準時) 2016>
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

using namespace std;

int proc(string s, string &res){
  int L = s.length();

  int ans = 0, i;
  for(i = 0; i < L; i++){
    if('0' <= s[i] && s[i] <= '9') 
      ans = ans * 10 + (s[i] - '0'); 
    else break;
  }
  res = s.substr(i);
  return ans;
}

int main(int argc, char **argv){
  string s;
  int ca = 0;
  while(cin >> s){
    ca++;
    if(s == "END") break;
    for(int i = 0; i < s.length(); i++)
      if(s[i] == '.' || s[i] == ',') s[i] = ' ';
    stringstream ss(s);
    string t;

    double y = 0.0, x = 0.0;
    while(ss >> t){
      string tmp;
      int d = proc(t, tmp);
      if(tmp == "N"){
	y += d * 1.0;
      } else if(tmp == "E"){ 
	x += d * 1.0;
      } else if(tmp == "S"){
	y -= d * 1.0;
      } else if(tmp == "W"){ 
	x -= d * 1.0;
      } else if(tmp == "NE"){
	x += d / sqrt(2.0);
	y += d / sqrt(2.0);
      } else if(tmp == "SE"){
	x += d / sqrt(2.0);
	y -= d / sqrt(2.0);
      } else if(tmp == "SW"){
	x -= d / sqrt(2.0);
	y -= d / sqrt(2.0);
      } else {
	x -= d / sqrt(2.0);
	y += d / sqrt(2.0);
      }
    }
    //cout << x << " " << y << endl;
    printf("Map #%d\n", ca);
    printf("The treasure is located at (%.3f,%.3f).\n", x, y);
    printf("The distance to the treasure is %.3f.\n\n", sqrt(x * x + y * y));
  }
  return 0;
}
