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
#include <numeric>
using namespace std;

int main()
{
  int n;
  while(cin >> n, n != 0){
    vector<int> perf(n);
    for(int i = 0; i < n; i++){
      cin >> perf[i];
    }
    int sum = accumulate(perf.begin(), perf.end(), 0);
    sum -= (*max_element(perf.begin(), perf.end()) + *min_element(perf.begin(), perf.end()));
    cout << sum / (n - 2) << endl;;
  }
  return 0;
}