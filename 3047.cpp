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

char day[7][10] = {
  "sunday", "monday",  "tuesday",  "wednesday",  "thursday",  "friday",  "saturday"
};

int main(){
  int y, m, d;
  cin >> y >> m >> d;

  if(m <= 2) m += 12, y--;

  int h = (y + (y / 4) - (y / 100)
	   + (y / 400) + (13 * m + 8) / 5 + d);

  
  printf("%s\n", day[h % 7]);
  return 0;
}