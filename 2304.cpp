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
  int pos, a1, a2, a3;
  while(cin >> pos >> a1 >> a2 >> a3){
    if(pos == 0 && a1 == 0 && a2 == 0
       && a3 == 0) break;
    int com = 0;
    com += 80;
    com += (pos - a1 + 40) % 40;
    com += 40;
    com += (a2 - a1 + 40) % 40;
    com += (a2 - a3 + 40) % 40;
    cout << com * 9 << endl;
  }
  return 0;
}