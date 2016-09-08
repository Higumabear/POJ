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

int main(int argc, char **argv){
  int N; cin >> N;
  vector<vector<int> > d(N, vector<int>(N, 0));

  for(int i = 0; i < N * N; i++)
    cin >> d[i / N][i % N];

  int sum = 0;

  vector<int> a(N), b(N);
  for(int S = 0; S < (1 << N); S++){
    int c = 0, e = 0;
    for(int i = 0; i < N; i++)
      if(S >> i & 1) a[c++] = i;
      else b[e++] = i;;

    int t = 0;
    for(int i = 0; i < c; i++)
      for(int j = 0; j < e; j++)
	t += d[a[i]][b[j]];
    sum = max(sum, t);
  }
  cout << sum << endl;
}
