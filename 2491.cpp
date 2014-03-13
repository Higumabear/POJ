//
// Time-stamp: <Thu Mar 13 18:40:44 “Œ‹ž (•W€Žž) 2014>
//
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
using namespace std;
static const double EPS = 1e-8;
static const int INF = 1 << 29;
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;

int main(){
  int T; cin >> T;
  for(int t = 1; t <= T; t++){
    map<string, string> rt;
    int n; cin >> n;
    string a, b;
    for(int i = 0; i < n - 1; i++){
      cin >> a >> b; 
      rt[a] = b;
    }

    map<string, string>::iterator it;
    vector<string> output;
    for(it = rt.begin(); it != rt.end(); it++){
      output.clear();
      string p = it->first;
      output.push_back(p);
      while(rt.count(p) != 0){
	p = rt[p];
	output.push_back(p);
      }
      if((int)output.size() == n){
	cout << "Scenario #" << t << ":" << endl;
	for(int i = 0; i < n; i++) cout << output[i] << endl;
	break;
      }
    }
    cout << endl;
  }
  return 0;
}
