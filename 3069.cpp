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

int x[1001];

int main(){
  int N, R;
  while(cin >> R >> N){
    if(R == -1 && N == -1) break;
    for(int i = 0; i < N; i++) cin >> x[i];
  
    sort(x, x + N);

    int i = 0;
    int ans = 0;
    while(i < N){
      int s = x[i++];
      while(i < N && x[i] <= s + R) i++;
    
      int p = x[i - 1];

      while(i < N && x[i] <= p + R) i++;

      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}