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
  string s;
  while(getline(cin, s), s != "#"){
    int N = s.length();
    for(int i = 0; i < N; i++){
      if(s[i] == ' ') cout << "%20";
      else if(s[i] == '!') cout << "%21";
      else if(s[i] == '$') cout << "%24";
      else if(s[i] == '%') cout << "%25";
      else if(s[i] == '(') cout << "%28";
      else if(s[i] == ')') cout << "%29";
      else if(s[i] == '*') cout << "%2a";
      else cout << s[i];
    }
    cout << endl;
  }
  return 0;
}