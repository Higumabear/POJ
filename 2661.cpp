#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

int main(int argc, char **argv){
  int y;
  while(cin >> y, y){
    int bit = 1 << ((y - 1940) / 10);
    int n = 1;
    double sum = 0;
    while(sum < bit){
      sum += log2(n);
      n++;
    }
    cout << n - 2<< endl;
  }
  return 0;
}
