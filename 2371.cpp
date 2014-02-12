#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 10000000;

int main(){
  int n; cin >> n;
  vector<int> db(n);
  for(int i = 0; i < n; i++) cin >> db[i];
  string sharp; cin >> sharp;
  sort(db.begin(), db.end());
  cin >> n;
  for(int i = 0; i < n; i++){
    int q; cin >> q;
    cout << db[q - 1] << endl;
  }
  return 0;
}