#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

int eat[2001];

int main(int argc, char **argv){
  int c, f1, f2, d;
  cin >> c >> f1 >> f2 >> d;
  for(int i = 0; i < c; i++){
    int f,t;
    cin >> f >> t;
    for(int j = f; j <= t; j++) eat[j]++;
  }
  for(int ans = d; ans >= 0; ans--){
    f2 += eat[ans];
    if(f1 == f2){
      cout << ans << endl;
      break;
    }
  }
}
