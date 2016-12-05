// Time-stamp: <Sun Dec 04 15:17:05 東京 (標準時) 2016>
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
  map<string, int> p;
  p["negative"] = -1; p["zero"] = 0; p["one"] = 1; p["two"] = 2;
  p["three"] = 3; p["four"] = 4; p["five"] = 5; p["six"] = 6;
  p["seven"] = 7; p["eight"] = 8; p["nine"] = 9; p["ten"] = 10;
  p["eleven"] = 11; p["twelve"] = 12; p["thirteen"] = 13; p["fourteen"] = 14;
  p["fifteen"] = 15; p["sixteen"] = 16; p["seventeen"] = 17; p["eighteen"] = 18; 
  p["nineteen"] = 19; 
  p["twenty"] = 20; p["thirty"] = 30; p["forty"] = 40; p["fifty"] = 50; 
  p["sixty"] = 60; p["seventy"] = 70; p["eighty"] = 80; p["ninety"] = 90; 
  p["hundred"] = 100; p["thousand"] = 1000; p["million"] = 1000000;


  char c[400];
  while(gets(c)){
    string s(c);
    if(s.empty()) break;
    stringstream ss(s);
    vector<string> v;
    while(ss >> s) v.push_back(s);
    reverse(ALL(v));
    
    vector<string> num[4];
    int digit = 0;
    for(int i = 0; i < v.size(); i++){
      if(v[i] == "hundred"		&& digit < 1) digit = 1;
      else if(v[i] == "thousand"	&& digit < 2) digit = 2;
      else if(v[i] == "million"		&& digit < 3) digit = 3;
      else num[digit].push_back(v[i]);
    }

    int ans = 0;
    int sign = 1;
    for(int i = 0; i < 4; i++){
      int base = 1, val = 0;
      for(int j = 0; j < num[i].size(); j++){
	if(p[num[i][j]] == -1) sign = -1;
	else if(p[num[i][j]] < 100){
	  val += base * p[num[i][j]];
	}else{
	  base = p[num[i][j]];
	}
      }
      if(i == 0) ans += val;      
      if(i == 1) ans += 100 * val;
      if(i == 2) ans += 1000 * val;
      if(i == 3) ans += 1000000 * val;
    }
    cout << sign * ans << endl;
  }
  return 0;
}
