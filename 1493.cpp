#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 10000000;

string parts[20];

int main(){
  int n;
  while(cin >> n, n){
    cin.ignore();
    for(int i = 0; i < n; i++)
      getline(cin, parts[i]);

    int maxX = 0;
    for(int i = 0; i < n; i++)
      maxX = max(maxX, (int)count(parts[i].begin(), parts[i].end(), 'X'));

    int ans = 0;
    for(int i = 0; i < n; i++){
      ans += (maxX - (int)count(parts[i].begin(), parts[i].end(), 'X'));
    }
    cout << ans << endl;
  }
  return 0;
}