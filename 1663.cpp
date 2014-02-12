#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
  int N;
  cin >> N;
  for(int i = 0; i < N; i++){
    int x, y;
    cin >> x >> y;
    if(x == y){
      if(x % 2 == 0) cout << 2 * x << endl;
      else cout << 2 * x - 1 << endl;
    }else if(y + 2 == x){
      if(x % 2 == 0) cout << 2 * x - 2 << endl;
      else cout << 2 * x - 3 << endl;
    }else cout << "No Number" << endl;
    
  }
  return 0;
}