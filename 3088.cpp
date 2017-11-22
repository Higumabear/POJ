#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll b[] = {0, 1, 5, 25, 149, 1081, 9365, 94585,
	   1091669, 14174521, 204495125, 3245265145};
int main(int argc, char **argv){
  int N;
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    int a;
    scanf("%d", &a);
    printf("%d %d %lld\n", i + 1, a, b[a]);
  }
}

