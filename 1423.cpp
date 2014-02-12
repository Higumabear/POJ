#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int main(int argc, char **argv){
  int n; cin >> n;
  while(n--){
    double a; cin >> a;
    cout << (int)(lgamma(a + 1) / log(10.0) + 1) << endl;
  }
  return 0;
}