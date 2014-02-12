#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>

using namespace std;

long long a[500001];

int main(int argc, char **argv){
  a[0] = 0;
  set<long long> rac;
  for(int i = 1; i <= 500000; i++){
    int t = a[i - 1] - i;
    int u = a[i - 1] + i;
    set<long long>::iterator it = rac.find(t);
    if(t > 0 && it == rac.end()){
      a[i] = t;
      rac.insert(t);
    }else{
      a[i] = u;
      rac.insert(u);
    }
  }

  int k;
  while(cin >> k, k != -1)
    cout << a[k] << endl;
  return 0;
}