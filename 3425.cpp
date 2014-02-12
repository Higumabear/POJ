// last update : 2013-04-26 23:41:37 nav

#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
typedef long long ll;

#define ALL(a)  (a).begin(),(a).end()

const int INF = 1 << 29;
const double EPS = 1e-7;

int main(int argc, char **argv){
  int mag[1001000];
  int N;
  //while(cin >> N, N){
    int ret = 0;
    cin >> N;
    memset(mag, 0, sizeof(mag));
    for(int i = 0; i < N; i++){
      int q, a, x;
      cin >> q >> a >> x;
      if(a == 1){
	ret += (mag[q] > 0) ? 10 : 0;

	if(x == 1)
	  ret += 40;
	else
	  ret += 20;
	
	mag[q]++;
      }else
	ret += 10;
    }
    cout << ret << endl;
    //}
}