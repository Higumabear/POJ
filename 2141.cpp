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
  string low;
  cin >> low;

  string up;
  for(int i = 0; i < 26; i++){
    up += (low[i] - 'a' + 'A');
  }

  cin.ignore();
  string input;
  getline(cin, input);

  int N = input.length();
  for(int i = 0; i < N; i++){
    if('a' <= input[i] && input[i] <= 'z'){
      cout << low[input[i] - 'a'];
    }else if ('A' <= input[i] && input[i] <= 'Z'){
      cout << up[input[i] - 'A'];
    }else{
      cout << input[i];
    }
  }
  cout << endl;
  return 0;
}