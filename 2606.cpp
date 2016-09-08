#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char **argv){
  int N;
  cin >> N;
  vector<int> X(N), Y(N);
  for(int i = 0; i < N; i++){
    int x, y;
    cin >> x >> y;
    X[i] = x, Y[i] = y;
  }

  int cnt = 0;
  for(int i = 0; i < N; i++){
    for(int j = i + 1; j < N; j++){
      int t = 0;
      for(int k = 0; k < N; k++)
	if((X[j] - X[i]) * (Y[k] - Y[i]) 
	   == (Y[j] - Y[i]) * (X[k] - X[i])) t++;
      cnt = max(cnt, t);
    }
  }
  cout << cnt << endl;
  return 0;
}
