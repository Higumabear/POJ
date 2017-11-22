// Time-stamp: <Mon Mar 06 21:38:26 東京 (標準時) 2017>
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

struct participant{
  int idx, solved, score;
};

bool cmp(participant a, participant b){
  if(a.solved != b.solved) return a.solved < b.solved;
  return a.score > b.score;
}

bool cmpr(participant a, participant b){
  if(a.solved != b.solved) return a.solved > b.solved;
  return a.score < b.score;
}

int main(int argc, char **argv){
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++){
    int ti, p;
    cin >> ti >> p;
    
    vector<int> d(p);
    for(int i = 0; i < p; i++) cin >> d[i];
    
    participant par[3];
    par[0].idx = 0, par[1].idx = 1, par[2].idx = 2;
    
    int score = 0, solved = 0, time = 0;
    for(int i = 0; i < p; i++){
      if(time + d[i] > ti) break;
      time += d[i];
      solved++;
      score += accumulate(d.begin(), d.begin() + i + 1, 0);
    }
    par[0].solved = solved, par[0].score = score;

    sort(ALL(d));
    score = 0, solved = 0, time = 0;
    for(int i = 0; i < p; i++){
      if(time + d[i] > ti) break;
      time += d[i];
      solved++;
      score += accumulate(d.begin(), d.begin() + i + 1, 0);
    }
    par[1].solved = solved, par[1].score = score;

    reverse(ALL(d));
    score = 0, solved = 0, time = 0;
    for(int i = 0; i < p; i++){
      if(time + d[i] > ti) break;
      time += d[i];
      solved++;
      score += accumulate(d.begin(), d.begin() + i + 1, 0);
    }
    par[2].solved = solved, par[2].score = score;

    sort(par, par + 3, cmpr);    

    if(par[0].solved != par[1].solved){
      string name;
      if(par[0].idx == 0) name = "Bill";
      if(par[0].idx == 1) name = "Steve";
      if(par[0].idx == 2) name = "Linus";
      cout << "Scenario #" << t << ":" << endl;
      cout << name << " wins with " << par[0].solved 
	   << " solved problems and a score of " 
	   << par[0].score << ".\n\n";
    }else{
      if(par[0].score == par[1].score){

	int pos;
	if(par[0].idx == 0) pos = 0;
	if(par[0].idx == 1) pos = 1;
	if(par[0].idx == 2) pos = 2;
	cout << "Scenario #" << t << ":" << endl;
	cout << "Steve wins with " << par[pos].solved 
	     << " solved problems and a score of " 
	     << par[pos].score << ".\n\n";
	
      }else{
	string name;
	if(par[0].idx == 0) name = "Bill";
	if(par[0].idx == 1) name = "Steve";
	if(par[0].idx == 2) name = "Linus";
	cout << "Scenario #" << t << ":" << endl;
	cout << name << " wins with " << par[0].solved 
	     << " solved problems and a score of " 
	     << par[0].score << ".\n\n";

      }
    }
  }
  return 0;
}
