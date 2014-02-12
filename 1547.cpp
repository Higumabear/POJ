#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n;
  while(cin >> n, n != -1){
    vector<pair<int, string> > cray(n);
    int a, b, c;
    string name;
    for(int i = 0; i < n; i++){
      cin >> a >> b >> c >> name;
      cray[i] = make_pair(a * b * c, name);
    }
    sort(cray.begin(), cray.end());
    cout << cray[n - 1].second << " took clay from "
	 << cray[0].second << "." << endl;
  }
}