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

int main(){
  int t;
  cin >> t;
  while(t--){
    int n; cin >> n;
    vector<int> rope;
    for(int i = 0; i < n; i++){
      int tmp; cin >> tmp;
      rope.push_back(tmp);
    }
    sort(rope.begin(), rope.end(), greater<int>());
    int ans = 0;
    for(int i = 0; i < (int)rope.size(); i++){
      ans = max(ans, (i + 1) * rope[i]);
    }
    cout << ans << endl;
  }
  return 0;
}