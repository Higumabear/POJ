#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int h[50010];

int main(int argc, char **argv){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> h[i];

  vector<int> ans;
  for(int i = 0; i < n; i++){
    bool use = true;
    if(0 <= i - 1 && !(h[i - 1] <= h[i])) use &= false;
    if(i + 1 < n && !(h[i] >=  h[i + 1])) use &= false;
    if(use) ans.push_back(i + 1);
  }
  for(int i = 0; i < (int)ans.size(); i++) cout << ans[i] << endl;
  return 0;
}