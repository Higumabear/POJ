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
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;

int main(){
  int N, M;
  cin >> N >> M;
  map<string, int> mp;
  while(N--){
    string s;
    int t;
    cin >> s >> t;
    mp[s] = t;
  }
  while(M--){
    string word;
    int point = 0;
    while(cin >> word){
      if(word == "."){
	cout << point << endl;
	break;
      }
      map<string, int>::iterator it = mp.begin();
      for(; it != mp.end(); it++)
	if(it -> first == word)
	  point += it->second;
    }
  }
  return 0;
}