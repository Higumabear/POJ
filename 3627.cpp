#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(int argc, char **argv){
  int n;
  ll m; cin >> n >> m;
  vector<int> cow;
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    cow.push_back(a);
  }
  sort(cow.begin(), cow.end());
  ll sum = 0;
  for(int i = (int)cow.size() - 1; i >= 0; i--){
    sum += cow[i];
    if(sum >= m){
      cout << (int)cow.size() - i << endl;
      break;
    }
  }
  return 0;
}