// Time-stamp: <Mon Feb 13 23:39:30 東京 (標準時) 2017>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <list>
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

int main(int argc, char **argv){
  int WIDTH;
  int cnt = 0;
  while(cin >> WIDTH){
    if(WIDTH == -1) break;
    char op;
    int id, w;
    deque<pair<int, int> > shelf;
    map<int, int> width;
    while(1){
      cin >> op;
      if(op == 'E') break;
      else if(op == 'R'){
	cin >> id;
	for(int i = 0; i < shelf.size(); i++)
	  if(shelf[i].first == id) 
	    shelf.erase(shelf.begin() + i);
      }else{
	cin >> id >> w;
	width[id] = w;
	shelf.push_front(make_pair(id, 0));
	for(int i = 1; i < shelf.size(); i++){
	  int prevw = width[shelf[i - 1].first];
	  int prevp = shelf[i - 1].second;
	  if(prevp + prevw >= shelf[i].second)
	    shelf[i].second = prevp + prevw;
	}
	for(int i = shelf.size() - 1; i >= 0; i--){
	  int wi = width[shelf[i].first];
	  int po = shelf[i].second;
	  if(po + wi > WIDTH) 
	    shelf.erase(shelf.begin() + i);
	}
      }
    }
    cout << "PROBLEM " << ++cnt << ": ";
    for(int i = 0; i < shelf.size(); i++)
      cout << shelf[i].first << " ";
    cout << endl;
  }
  return 0;
}
