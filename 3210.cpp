// Time-stamp: <Sat May 21 04:28:52 東京 (標準時) 2016>
#include <sstream>
#include <iostream>

using namespace std;

int main(int argc, char **argv){
  int N;
  while(cin >> N, N){
    if(N % 2 == 0) cout << "No Solution!" << endl;
    else
      cout << N - 1 << endl;
  }
  return 0;
}