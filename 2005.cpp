// Time-stamp: <Mon Nov 14 23:34:51 東京 (標準時) 2016>
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

int p(char c){
  if(c == 'A') return 1;
  else if(isdigit(c)) return (int)(c - '0');
  else return 10;
}
int num(char c){
  if(c == 'A') return 1;
  if(c == 'K') return 13;
  if(c == 'Q') return 12;
  if(c == 'J') return 11;
  if(c == 'T') return 10;
  return (int)(c - '0');
}
int main(int argc, char **argv){
  int card[14];
  int n;
  while(cin >> n, n){
    if(n == 0) break;
    for(int i = 1; i <= 13; i++) card[i] = 4 * n;

    int dealer = 0, me = 0;
    char a, b, c;
    cin >> a >> b >> c;
    card[num(a)]--;
    card[num(b)]--;
    card[num(c)]--;
    
    me = p(b) + p(c);
    if(b == 'A' || c == 'A') me = (me + 10 <= 21) ? me + 10 : me;

    int chance = 0;
    if(a == 'A'){
      for(int i = 1; i <= 13; i++){
	if(i == 1){
	  dealer = 12;
	  if(dealer < me && me <= 21) chance += card[i];
	}else{
	  dealer = min(10, i) + 11;
	  if(dealer > 21) dealer -= 10;
	  if(dealer < me && me <= 21) chance += card[i];
	}
      }
      printf("%.3f\%\n\n", chance * 100.0 / (n * 52 - 3));
    }else{
      for(int i = 1; i <= 13; i++){
	dealer = p(a);
	if(i == 1){
	  dealer += 11;
	  if(dealer > 21) dealer -= 10;
	  if(dealer < me && me <= 21) chance += card[i];
	}else{
	  dealer += min(i, 10);
	  if((dealer > 21 && me <= 21) || (dealer < me && me <= 21))
	    chance += card[i];
	}
      }
      printf("%.3f\%\n\n", chance * 100.0 / (n * 52 - 3));      
    }
  }
  return 0;
}
