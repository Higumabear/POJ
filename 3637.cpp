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

int main()
{
  int n; cin >> n;
  for(int i = 0; i < n; i++){
    int num; cin >> num;
    vector<int> price(num);
    for(int j = 0; j < num; j++) cin >> price[j];
    sort(price.begin(), price.end(), greater<int>());
    
    int discount = 0;
    for(int j = 2; j < num; j += 3) discount += price[j];
    cout << discount << endl;
  }
  return 0;
}