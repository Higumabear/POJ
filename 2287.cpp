#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, char **argv){
  int n;
  while(cin >> n, n){
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    int la = 0, lb = 0, ra = n - 1, rb = n - 1;
    for(int i = 0; i < n; i++){
      if(a[la] > b[lb]){
	ans += 200;
	la++;
	lb++;
      }else if(a[ra] > b[rb]){
	ans += 200;
	ra--;
	rb--;
      }else{
	if(a[la] < b[rb])
	  ans -= 200;
	la++;
	rb--;
      }
    }
    cout << ans << endl;
  }
  return 0;
}