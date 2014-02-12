#include <iostream>

using namespace std;

int main(){
  int l, r;
  while(cin >> l >> r){
    if(l == 0 && r == 0) break;
    int init = l + 1;
    for(int i = 0; i < r; i++){
      int cutl, cutr;
      cin >> cutl >> cutr;
      init -= (cutr - cutl + 1);
    }
    cout << init << endl;
  }
  return 0;
}