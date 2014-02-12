/*
 * 2328.cpp
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

int main(){
  int n;
  bool ok[11];
  fill(ok, ok + 11, true);

  while(cin >> n, n != 0){
    cin.ignore();
    string s; getline(cin, s);
    if(s.find("high", 0) != string::npos){
      for(int i = n; i <= 10; i++) ok[i] = false;
    }else if(s.find("low", 0) != string::npos){
      for(int i = 0; i <= n; i++) ok[i] = false;
    }else{
      if(ok[n]) cout << "Stan may be honest" << endl;
      else cout << "Stan is dishonest" << endl;
      fill(ok, ok + 11, true);
    }
  }
  return 0;
}