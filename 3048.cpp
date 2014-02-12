#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<int, int> prime_factor(int n){
  map<int, int> ret;
  for(int i = 2; i * i <= n; i++){
    while(n % i == 0){
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

int main(int argc, char **argv){
  int n; cin >> n;
  int maxval = 0;
  int index = -1;
  int a;
  for(int i = 0; i < n; i++){
    cin >> a;
    if(a != 1){
      map<int, int> mp = prime_factor(a);
      map<int, int>::reverse_iterator it = mp.rbegin();
      if(maxval < it -> first){
	maxval = it->first;
	index = a;
      }
    }else{
      if(maxval < a){
	maxval = a;
	index = a;
      }
    }
  }
  cout << index << endl;
  return 0;
}