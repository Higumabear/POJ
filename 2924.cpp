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

int main()
{
  int N; cin >> N;
  for(int i = 1; i <= N; i++){
    long long n, m;
    cin >> n >> m;
    if(0 <= n && 0 <= m){
      cout << "Scenario #" << i << ":" << endl
        << m * (m + 1) / 2 - n * (n - 1) / 2 << endl;
    }else if(n < 0 && 0 <= m){
      cout << "Scenario #" << i << ":" << endl
        << m * (m + 1) / 2 - n * (n - 1) / 2 << endl;
    }else{
      cout << "Scenario #" << i << ":" << endl
        << -n * (n - 1) / 2 - (-m) * (m + 1) / 2 << endl;
    }
    cout << endl;
  }
  return 0;
}