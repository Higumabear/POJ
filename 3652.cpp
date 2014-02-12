// last update : 2013-04-26 23:03:31 nav

#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
typedef long long ll;

#define ALL(a)  (a).begin(),(a).end()

const int INF = 1 << 29;
const double EPS = 1e-7;

string int2bit(int a){
  string ret;
  for(int i = 0; i < 16; i++)
    if(a >> i & 1)
      ret += '1';
    else
      ret += '0';
  reverse(ALL(ret));
  return ret;
}

int main(int argc, char **argv){
  int A, B, C, S;
  while(cin >> A, A){
    cin >> B >> C >> S;

    vector<string> bits;
    set<int> b;
    for(int i = 0; ; i++){
      if(!b.insert(S).second) break;
      bits.push_back(int2bit(S));
      S = (A * S + B) % C;
    }
    
    string ret;
    for(int i = 0; i < 16; i++){
      bool f0 = false, f1 = false;
      for(int j = 0; j < bits.size(); j++){
	if(bits[j][i] == '0')
	  f0 = true;
	else
	  f1 = true;
      }
      if(f0 && f1) ret += '?';
      else if(f0) ret += '0';
      else ret += '1';
    }
    cout << ret << endl;
  }
}