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

vector<int> pf(int n){
  vector<int> ans;
  for(int i = 2; i * i <= n; i++){
    if(n % i == 0){
      ans.push_back(i);
      while(n % i == 0) n /= i;
    }
  }
  if(n != 1) ans.push_back(n);
  return ans;
}

int main(int argc, char **argv){
  int N;
  while(cin >> N, N){
    int ans = 0;
    vector<int> p = pf(N);

    int L = p.size();
    for(int S = 1; S < 1 << L; S++){
      int div = 1;
      for(int i = 0; i < L; i++)
	if(S >> i & 1)
	  div *= p[i];

      if(__builtin_popcount(S) % 2 == 1)
	ans += (N / div);
      else
	ans -= (N / div);
    }
    cout << N - ans << endl;
  }
}
