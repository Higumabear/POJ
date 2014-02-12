#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char **argv){
  int N, K;
  scanf("%d %d", &N, &K);
  vector<pair<int, pair<int, int> > > vp(N);
  for(int i = 0; i < N; i++){
    scanf("%d %d", &vp[i].first, &vp[i].second.first);
    vp[i].second.second = i + 1;
  }

  sort(vp.begin(), vp.end());

  vector<pair<int, int> > svp(K);
  for(int i = 0; i < K; i++){
    svp[i].first = vp[N - 1 - i].second.first;
    svp[i].second = vp[N - 1 - i].second.second;
  }
  sort(svp.begin(), svp.end());
  printf("%d\n", svp[K - 1].second);
  return 0;
}