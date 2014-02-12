#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;


int main(int argc, char **argv){
  int a;
  while(cin >> a, a != 0){
    string mes;
    cin >> mes;
    for(int i = a; i < mes.length(); i += 2 * a){
      reverse(mes.begin() + i, mes.begin() + a + i);
    }
    for(int i = 0; i < a; i++){
      for(int j = i; j < mes.length(); j += a)
	cout << mes[j];
    }
    cout << endl;
  }
  return 0;
}