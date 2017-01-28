// Time-stamp: <Mon Jan 16 21:12:46 東京 (標準時) 2017>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

long long N;
char memo[20000000];
bool rec(long long p){
  if(p >= N) return false;
  if(p < 20000000 && memo[p] != -1) return memo[p];
  bool a = true;
  for(int i = 2; i <= 9; i++) a &= rec(p * i);
  if(p < 20000000) memo[p] = !a;
  return !a;
}
int main(int argc, char **argv){
  while(cin >> N){
    memset(memo, -1, sizeof(memo));
    cout << (rec(1) ? "Stan" : "Ollie") << " wins." << endl;
  }
  return 0;
}
