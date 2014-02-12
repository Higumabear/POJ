#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 10000000;

int main(){
  int a[4];
  while(cin >> a[0] >> a[1] >> a[2] >> a[3]){
    if(a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0) break;
    if(a[0] < a[1]) swap(a[0], a[1]);
    if(a[2] < a[3]) swap(a[2], a[3]);
    cout << min(100, min(100 * a[2] / a[0], 100 * a[3] / a[1]))
	 << "%" << endl;
  }
  return 0;
}