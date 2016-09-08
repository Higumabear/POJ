#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

#define ALL(c) (c).begin(), (c).end()

int main(int argc, char **argv){
  int N;
  cin >> N;
  vector<int> vo(N);
  for(int i = 0; i < N; i++) cin >> vo[i];
  sort(ALL(vo));
  
  int ans = 0;
  for(int i = 0; i < (N + 1) / 2; i++)
    ans += (vo[i] + 1) / 2;
  cout << ans << endl;
}
