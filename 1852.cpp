#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;

int m, L, n, a[1000000];

int main(){
  cin >> m;
  for(int j = 0; j < m; j++){
    cin >> L >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    int maxans = 0;
    int minans = 0;
    for(int i = 0; i < n; i++){
      minans = max(minans, min(a[i], L - a[i]));
      maxans = max(maxans, max(a[i], L - a[i]));
    }
    cout << minans << " " << maxans << endl;
  }
  return 0;
}