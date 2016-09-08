#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <numeric>
#include <algorithm>

using namespace std;

int main(int argc, char **argv){
  int N, M;
  cin >> N >> M;
  int d[10];
  for(int i = 0; i < N; i++) d[i] = i + 1;
  do{
    int prev[10] = {0}, nex[10] = {0};
    memcpy(prev, d, sizeof(int) * 10);
    for(int i = N - 2; i >= 0; i--){
      for(int j = 0; j <= i; j++){
	nex[j] = prev[j] + prev[j + 1];
	//cout << nex[i] << " ";
      }
      //cout << endl;
      memcpy(prev, nex, sizeof(int) * 10);
    }
    //cout << nex[0] << endl;
    if(prev[0] == M) break;
  }while(next_permutation(d, d + N));

  for(int i = 0; i < N; i++)
    cout << d[i] << " ";
  cout << endl;
}
