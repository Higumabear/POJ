#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char **argv){
  int n;
  while(cin >> n, n != 0){
    int b = 1;
    while(b * (b + 1) < n * 2) b++;
    int coin = 0;
    for(int i = 1; i < b; i++) coin += i * i;
    coin += (n - b * (b - 1) / 2) * b;
    cout << n << " " << coin << endl;
  }
  return 0;
}