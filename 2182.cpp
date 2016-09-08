#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

#define ALL(c) (c).begin(), (c).end()

int main(int argc, char **argv){
  int N;
  cin >> N;
  vector<int> d(N - 1), e(N);
  for(int i = 0; i < N - 1; i++){
    int a; cin >> a;
    d[i] = a;
  }
  
  for(int i = 0; i < N; i++)
    e[i] = i + 1;

  vector<int> ans;
  for(int i = N - 2; i >= 0; i--){
    ans.push_back(e[d[i]]);
    e.erase(e.begin() + d[i]);
  }
  ans.push_back(e[0]);
  reverse(ALL(ans));

  for(int i = 0; i < N; i++)
    cout << ans[i] << endl;
  return 0;
}
