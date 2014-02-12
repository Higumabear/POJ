#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <bitset>
using namespace std;
typedef long long ll;
const int INF = 10000000;

int main(){
  int n;
  while(cin >> n, n){
    int s = __builtin_popcount(n);
    int i;
    for(i = n + 1; __builtin_popcount(i) != s; i++);

    cout << i << endl;
  }
  return 0;
}