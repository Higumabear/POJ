// Time-stamp: <Sat Jan 28 23:08:08 東京 (標準時) 2017>
#include <iostream>

using namespace std;

int main(int argc, char **argv){
  int N;
  while(cin >> N) cout << ((N & (N - 1)) ? "NO" : "YES") << endl;
  return 0;
}
