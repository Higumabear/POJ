#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

int tall[20];

int main(int argc, char **argv){
  int N, B;
  cin >> N >> B;
  for(int i = 0; i < N; i++) cin >> tall[i];

  int ans = 2000000000;
  int use[20];
  for(int S = 0; S < 1 << N; S++){
    int c = 0;
    for(int i = 0; i < N; i++){
      if(S >> i & 1) use[c++] = tall[i];
    }
    int height = accumulate(use, use + c, 0);
    if(height >= B) ans = min(ans, height - B);
  }
  cout << ans << endl;
  return 0;
}