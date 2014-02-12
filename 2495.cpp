#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 10000000;

int main(){
  int k; cin >> k;
  for(int i = 1; i <= k; i++){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if((a + b) % 2 != (c + d) % 2)
      cout << "Scenario #" << i << ":" << endl << 1 << endl << endl;
    else      
      cout << "Scenario #" << i << ":" << endl << 0 << endl << endl;
    
  }
  return 0;
}