#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, char **argv){
  string t;
  while(cin >> t, t != "0"){
    int len = t.length();
    reverse(t.begin(), t.end());
    long long num = 0;
    for(long long i = 0; i < (long long)len; i++){
      num += ((1 << (i + 1)) - 1) * (t[i] - '0');
    }
    cout << num << endl;
  }
  return 0;
}