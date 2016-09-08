// Time-stamp: <Tue May 17 23:05:08 東京 (標準時) 2016>
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

bool prime(int n){
  for(int i = 2; i * i <= n; i++) 
    if(n % i == 0) return false;
  return true;
}

int main(int argc, char **argv){
  int N; cin >> N;
  while(N--){
    int s, t; cin >> s >> t;
    
    queue<int> Q;
    Q.push(s);
    int dist[10000];
    fill(dist, dist + 10000, -1);
    dist[s] = 0;
    while(!Q.empty()){
      int a = Q.front(); Q.pop();

      if(a == t) break;
      
      for(int base = 1; base <= 1000; base *= 10){
	for(int digit = 0; digit < 10; digit++){
	  int x = a;
	  x = x - x % (base * 10) + x % base;
	  x += base * digit;
	  if(x >= 1000 && prime(x) && dist[x] == -1){
	    dist[x] = dist[a] + 1;
	    Q.push(x);
	  }
	}
      }
    }
    if(dist[t] == -1) cout << "Impossible" << endl;
    else cout << dist[t] << endl;
  }
  return 0;
}
