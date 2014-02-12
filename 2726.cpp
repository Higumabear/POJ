#include<cstdio>
#include<utility>
#include<algorithm>

using namespace std;

int main()
{
  int N;
  pair<int, int> H[10000];
  while(scanf("%d", &N), N) {
    for(int i=0; i<N; ++i) scanf("%d%d", &H[i].first, &H[i].second);
    sort(H, H+N);
    int lo=100000, sol=0;
    for(int i=0; i<N; ++i)
      if(H[i].second<lo) { lo=H[i].second; sol++; }
    printf("%d\n", sol);
  }
  return 0;
}