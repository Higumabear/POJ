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

const double PI = 3.1415927;

int main(){
  int k = 0;
  double a, b, c;
  while(cin >> a >> b >> c, b > 0.0){
    printf("Trip #%d: %.2f %.2f\n",
	   ++k, a * PI * b / 63360.0, a * PI * b / 63360.0 * 3600.0 / c);
  }
  return 0;
}