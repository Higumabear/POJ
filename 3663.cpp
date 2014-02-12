#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int cow[20000];

int main(int argc, char **argv){
  int n, s;
  scanf("%d %d", &n, &s);
  for(int i = 0; i < n; i++) scanf("%d", &cow[i]);
  sort(cow, cow + n);


  int i;
  for(i = 0; i < n && cow[i] < s; i++);

  int cnt = 0;
  for(int p = 0; p < i - 1; p++)
    for(int q = p + 1; q < i; q++)
      if(cow[p] + cow[q] <= s) cnt++;
      else break;
  printf("%d\n", cnt);
  return 0;
}