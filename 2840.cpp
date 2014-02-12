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
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int h, m;
    char c;
    scanf("%d%c%d", &h, &c, &m);

    if(m != 0) cout << 0 << endl;
    else{
      cout << (h + 11) % 24 + 1 << endl;
    }
  }
  return 0;
}