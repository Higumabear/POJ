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
const double eps = 1e-7;
const double PI = 3.141592653;

int D, V;
int main(){
  while(cin >> D >> V){
    if(D == 0 && V == 0) break;
    printf("%.3f\n", pow(D * D * D - 6 * V / PI, 1 / 3.0));
  }
  return 0;
}
