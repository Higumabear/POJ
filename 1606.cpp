// Time-stamp: <Sat Dec 24 17:38:10 東京 (標準時) 2016>
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
int ca, cb, n;
bool memo[1001][1001];
deque<int> ans;

void rec(int a, int b, deque<int> t){
  if(a == n || b == n){
    ans = t;
    return;
  }
  if(!ans.empty() || memo[a][b]) return;
  memo[a][b] = true;
  if(a != ca){
    t.push_back(0);
    rec(ca, b, t); // full A
    t.pop_back();
  }
  if(b != cb){
    t.push_back(1);
    rec(a, cb, t); // full B
    t.pop_back();
  }
  if(a != 0){
    t.push_back(2);
    rec(0, b, t); // empty A
    t.pop_back();
    t.push_back(4);
    int chg = min(a, cb - b);
    rec(a - chg, b + chg, t); //pour A B
    t.pop_back();
  }
  if(b != 0){
    t.push_back(3);
    rec(a, 0, t); // empty B
    t.pop_back();
    t.push_back(5);
    int chg = min(b, ca - a);
    rec(a + chg, b, t); //pour B A
    t.pop_back();
  }
  return;
}
string str[] = {
  "fill A", "fill B", "empty A", "empty B", 
  "pour A B", "pour B A",
};
int main(int argc, char **argv){
  while(cin >> ca >> cb >> n){
    FILL(memo, false);
    ans.clear();
    rec(0, 0, deque<int>());
    deque<int>::iterator it = ans.begin();
    for(; it != ans.end(); it++) cout << str[*it] << endl;
    cout << "success" << endl;
  }
  return 0;
}
