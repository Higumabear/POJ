#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 10000000;

int main(){

  int a;
  double b;
  while(cin >> a >> b){
    cout << (int)(pow(b, 1.0 / a) + 0.5) << endl;
  }
  return 0;
}