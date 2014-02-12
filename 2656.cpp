#include <iostream>

using namespace std;

int main(int argc, char **argv){
  int n;
  while(cin >> n, n != 0){
    int a, b, maxhour = 0, day = 0;
    for(int i = 0; i < n; i++){
      cin >> a >> b;
      if(a + b > 8){
	if(maxhour < a + b){
	  maxhour = a + b;
	  day = i + 1;
	}
      }
    }
    cout << day << endl;
  }
  return 0;
}