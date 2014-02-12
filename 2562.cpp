/*
 * 2562.cpp
 *
 * Last update: <>
 */

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <numeric>
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;

/* string 型同士の足し算 */
int plustring(string a, string b){
  if(a.length() < b.length()) swap(a, b);
  a = string(1, '0') + a;
  b = string(a.length() - b.length() + 1, '0') + b;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  int ret = 0;

  int kuriagari = 0;
  int amari = 0;    
  for(int i = 0; i < (int)a.length(); i++){
    int wa = (a[i] - '0') + (b[i] - '0') + kuriagari;
    kuriagari = wa / 10;
    amari = wa % 10;
    a[i] = amari + '0';
    if(kuriagari > 0) ret++;
  }
  return ret;
}



int main(){
  string a, b;
  while(cin >> a >> b){
    if(a == "0" && b == "0") break;
    int c = plustring(a, b);
    
    if(c == 0) cout << "No carry operation." << endl;
    else if(c == 1) cout << "1 carry operation." << endl;
    else cout << c << " carry operations." << endl;
  }
  return 0;
}