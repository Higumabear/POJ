#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char **argv){
  int n;
  int se = 1;
  while(cin >> n, n != 0){
    bool used[n];
    fill(used, used + n, false);
    vector<string> name(n);
    for(int i = 0; i < n; i++) cin >> name[i];

    cout << "SET " << se << endl;
    for(int i = 0; i < n; i += 2){
      cout << name[i] << endl;
      used[i] = true;
    }
    for(int i = n - 1; i >= 0; i--){
      if(!used[i])
	cout << name[i] << endl;
    }

    se++;
  }
  return 0;
}