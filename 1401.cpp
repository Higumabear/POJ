#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char **argv){
  int n; cin >> n;
  while(n--){
    long long p; cin >> p;
    int num = 0;
    while(p / 5){
      p /= 5;
      num += p;

    }
    cout << num << endl;
  }
  return 0;
}