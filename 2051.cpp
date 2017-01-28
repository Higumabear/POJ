// Time-stamp: <Wed Jan 25 21:08:22 東京 (標準時) 2017>
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

struct query{
  int time, id;
  query(int time, int id) : time(time), id(id) {}
};

struct cmp_q{
  bool operator()(query a, query b)const{
    if(a.time != b.time) return a.time > b.time;
    else return a.id > b.id;
  }
};

int main(int argc, char **argv){
  string s;
  int id, v;
  map<int, int> interval;
  priority_queue<query, vector<query>, cmp_q> q;
  while(cin >> s){
    if(s == "#") break;
    cin >> id >> v;
    q.push(query(v, id));
    interval[id] = v;
  }
  int K;
  cin >> K;
  for(int i = 0; i < K; i++){
    query que = q.top(); q.pop();
    cout << que.id << endl;
    que.time += interval[que.id];
    q.push(que);
  }
  return 0;
}
