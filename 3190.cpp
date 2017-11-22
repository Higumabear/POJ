// Time-stamp: <Thu Mar 23 21:58:21 東京 (標準時) 2017>
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
template<typename A, size_t N, typename T>
void FILL(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

using namespace std;

//pair<int, pair<int, int> > e[50001];
struct cow{
  int s, e, idx;
  bool operator<(cow r)const{
    return s == r.s ? e < r.e : s < r.s;
  }
};

cow job[50001];
int stall[50001];

int main(int argc, char **argv){
  int N;
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    int s, e;
    scanf("%d %d", &s, &e);
    job[i] = (cow){s, e, i};
  }
  sort(job, job + N);
  
  int ans = 0;
  priority_queue<pair<int, int>, 
  		 vector<pair<int, int> >, 
  		 greater<pair<int, int> > > Q;

  for(int i = 0; i < N; i++){
    int s = job[i].s, e = job[i].e, idx = job[i].idx;
    if(Q.empty() || s <= Q.top().first){
      ans++;
      stall[idx] = ans;
      Q.push(make_pair(e, ans));
    }else{
      stall[idx] = Q.top().second;
      Q.pop();
      Q.push(make_pair(e, stall[idx]));
    }
  }

  printf("%d\n", ans);
  for(int i = 0; i < N; i++)
    printf("%d\n", stall[i]);
  return 0;
}
