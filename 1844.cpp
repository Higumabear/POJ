/*
 * 1844.cpp
 *
 * Last update: <2012年/12月/26日 16時44分29秒>
 */
#include <iostream>
using namespace std;

int main(int argc, char **argv){
  int n, sum, i; cin >> n;
  sum = 0;
  for(i = 1; (sum < n) || ((sum - n) % 2 == 1); i++)
    sum += i;
  cout << i - 1 << endl;
  return 0;
}