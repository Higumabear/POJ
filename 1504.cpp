/*
 * 1504.cpp
 *
 * Last update: <05/16/2013 23:07:07>
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

#define ALL(c) (c).begin(), (c).end()
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;


int main(){
  int n;
  cin >> n;
  while(n--){
    string s, t;
    cin >> s >> t;
    
    int i;
    for(i = (int)s.length() - 1; i >= 0; i--)
      if(s[i] != '0') break;

    if(i != -1)
      s = s.substr(0, i + 1);

    for(i = (int)t.length() - 1; i >= 0; i--)
      if(t[i] != '0') break;

    if(i != -1)
      t = t.substr(0, i + 1);

    reverse(ALL(s));
    reverse(ALL(t));

    stringstream ss, tt, uu;
    int p, q;
    ss << s, tt << t;
    ss >> p, tt >> q;
    
    int r = p + q;
    uu << r;

    string tmp, ret;
    uu >> tmp;

    for(i = (int)tmp.length() - 1; i >= 0; i--)
      if(tmp[i] != '0') break;

    if(i != -1)
      tmp = tmp.substr(0, i + 1);
    reverse(ALL(tmp));
    cout << tmp << endl;
  }
  return 0;
}
