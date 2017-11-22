#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>
#define ALL(c) (c).begin(), (c).end()

using namespace std;

int main(){
  int N, L;
  scanf("%d %d", &N, &L);

  multiset<int> x;
  for(int i = 0; i < N; i++){
    int a;
    scanf("%d", &a);
    x.insert(a);
  }

  int ans = 0;
  while(!x.empty()){
    int b = L - *x.begin();
    multiset<int>::iterator it = x.begin();
    it =  x.upper_bound(b);
    if(it != x.begin()) it--;
    
    if(it != x.begin()) x.erase(it);
    x.erase(x.begin());
    ans++;
  }
  //if(x.size() == 1) ans++;
  printf("%d\n", ans);
  return 0;
}