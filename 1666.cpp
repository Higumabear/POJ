#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int candy[1000];
int tmp[1000];

int main(int argc, char **argv){
  int N;
  while(cin >> N, N){
    for(int i = 0; i < N; i++) cin >> candy[i];
    
    int blow = 0;
    while(count(candy, candy + N, candy[0]) != N){
      blow++;//blows
      
      //give candy
      for(int i = 0; i < N; i++) tmp[i] = (candy[i] / 2);
      for(int i = 0; i < N; i++){
	candy[(i + 1) % N] += tmp[i];
	candy[i] -= tmp[i];
      }

      //check odd
      for(int i = 0; i < N; i++)
	if(candy[i] % 2 == 1) candy[i]++;
    }
    cout << blow << " " << candy[0] << endl;
  }
  return 0;
}