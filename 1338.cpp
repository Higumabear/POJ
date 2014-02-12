#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;

ll num[2000];

int main(){
  int k = 0;
  priority_queue<ll, vector<ll>, greater<ll> > q;
  set<ll> visit;
  q.push(1);
  while(!q.empty() && k < 1600){
    ll a = q.top(); q.pop();
    if(!visit.insert(a).second) continue;
    num[k++] = a;
    q.push(a * 2), q.push(a * 3), q.push(a * 5);
  }
  sort(num, num + k);
  int n;
  while(cin >> n, n) cout << num[n - 1] << endl;
}