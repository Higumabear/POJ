#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

int main(int argc, char **argv){
  int d[20], K;
  bool in = false;
  while(cin >> K){
    if(K == 0) break;
    else{
      if(in)
	cout << endl;
    }
    in = true;
    for(int i = 0; i < K; i++) cin >> d[i];

    vector<vector<int> > a;
    for(int S = 0; S < 1 << K; S++){
      if(__builtin_popcount(S) != 6) continue;

      vector<int> b(6);
      for(int i = 0, j = 0; i < K; i++)
	if(S >> i & 1) b[j++] = d[i];

      a.push_back(b);
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < a.size(); i++){
      for(int j = 0; j < 6; j++)
	cout << a[i][j] << " ";
      cout << endl;
    }
  }
}
