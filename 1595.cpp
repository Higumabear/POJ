// Time-stamp: <Sun Aug 07 13:27:34 東京 (標準時) 2016>
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

bool si[1001];
void sieve(int k){
  FILL(si, true);
  si[0] = false;
  for(int i = 2; i <= 1000; i++){
    if(!si[i]) continue;
    for(int j = 2 * i; j <= 1000; j += i) si[j] = false;
  }
}
int main(int argc, char **argv){
  int N, C;
  while(cin >> N >> C){
    vector<int> p;
    sieve(N);
    for(int i = 0; i <= N; i++)
      if(si[i]) p.push_back(i);

    int T = p.size() / 2;
    //cout << p.size() << " " << p[T] << endl;

    vector<int> q;
    if(p.size() % 2 == 1){
      for(int i = 0; i < C && T + i < p.size(); i++)
	q.push_back(p[T + i]);
      for(int i = 0; i < C - 1 && T - 1 - i >= 0; i++)
	q.push_back(p[T - 1 - i]);
    }else{
      for(int i = 0; i < C && T + i < p.size(); i++)
	q.push_back(p[T + i]);
      for(int i = 0; i < C && T - 1 - i >= 0; i++)
	q.push_back(p[T - 1 - i]);
    }
    sort(ALL(q));
    cout << N << " " << C << ": ";
    for(int i = 0; i < q.size(); i++)
      cout << q[i] << " ";
    cout << endl << endl;;
  }

  return 0;
}