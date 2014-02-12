#include <iostream>
using namespace std;

int main(){
  int a;
  while(cin >> a){
    if(a == -1) break;
    int speed, mile, prev = 0;
    int distance = 0;
    for(int i = 0; i < a; i++){
      cin >> speed >> mile;
      distance += speed * (mile - prev);
      prev = mile;
    }
    cout << distance << " miles" << endl;
  }
}