// Time-stamp: <Sat May 21 04:47:37 東京 (標準時) 2016>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 60
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define CNT(c,x) count(ALL(c),x)
#define dump(x)  cerr << #x << " = " << (x) << endl;

using namespace std;

int main(int argc, char **argv){
  set<ll> q;
  q.insert(1);

  vector<ll> hum;
  set<ll>::iterator it = q.begin();
  for(int i = 0; i < 7000; i++){
    ll t = *it;
    hum.push_back(t);
    q.insert(t * 2); q.insert(t * 3); q.insert(t * 5); q.insert(t * 7);
    it++;
  }
  
  int n;
  while(scanf("%d", &n), n){
    int c = n % 100;
    if(c == 11 || c == 12 || c == 13) 
      printf("The %dth humble number is %d.\n", n, hum[n - 1]);
    else if(n % 10 == 1)
      printf("The %dst humble number is %d.\n", n, hum[n - 1]);
    else if(n % 10 == 2)
      printf("The %dnd humble number is %d.\n", n, hum[n - 1]);
    else if(n % 10 == 3)
      printf("The %drd humble number is %d.\n", n, hum[n - 1]);
    else
      printf("The %dth humble number is %d.\n", n, hum[n - 1]);
  }
  return 0;
}
