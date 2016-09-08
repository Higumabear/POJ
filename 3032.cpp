#include <iostream>
#include <vector>
using namespace std;
 
int main(int argc, char **argv){
  int n; cin >> n;
  for(int i = 0; i < n; i++){
    int m; cin >> m;
    vector<int> t(m, -1);

    int idx = 0;
    for(int j = 1; j <= m; j++){
      int T = j + 1;
      while(1){
	if(t[idx] == -1) T--;
	if(T == 0){
	  t[idx] = j;
	  break;
	}
	idx = (idx + 1) % m;
      }
    }
    for(int j = 0; j < m; j++) cout << t[j] << " ";
    cout << endl;
  }
}
