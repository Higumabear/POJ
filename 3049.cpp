#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 10000000;

char ch[20];

int main(){
  int L, C;
  cin >> L >> C;
  for(int i = 0; i < C; i++) cin >> ch[i];
  sort(ch, ch + C);

  vector<string> ans;
  for(int S = 0; S < 1 << C; S++){
    string cand;

    bool vowel = false;
    for(int i = 0; i < C; i++){
      if(S >> i & 1){
	if(ch[i] == 'a' ||
	   ch[i] == 'u' ||
	   ch[i] == 'i' ||
	   ch[i] == 'e' ||
	   ch[i] == 'o') vowel = true;
	cand += ch[i];
      }
    }
    if((int)cand.size() == L && vowel){
      ans.push_back(cand);
    }
  }

  sort(ans.begin(), ans.end());
  for(int j = 0; j < (int)ans.size(); j++){
    cout << ans[j] << endl;
  }
    
  return 0;
}