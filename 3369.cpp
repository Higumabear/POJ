#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 100000;
typedef long long ll;

const ll M = 1000000LL;

int main(){
  int cnt = 0;
  for(ll a = 1; a <= 2000; a++){
    for(ll b = a; a + b <= 2000; b++){
      ll r = (1.0 * M + sqrt(1.0 * M * M + 1.0 * M * a * b * (a + b))) / (a * b);
      for(ll c = b; c <= min(r + 10, 2000 - a - b - c); c++){
	if(a * b * c > M){
	  ll rem = M * (a + b + c) % (a * b * c - M);
	  ll d = M * (a + b + c) / (a * b * c - M);
	  if(rem == 0 && c <= d && a + b + c + d <= 2000){
	    cnt++;
	    printf("%.2f %.2f %.2f %.2f\n", 
		   a / 100.0, b / 100.0, c / 100.0, d / 100.0);
	    
	  }
	}
      }
      //ll r = (1.0 * M + sqrt(1.0 * M * M + 1.0 * M * a * b * (a + b))) / (a * b);
      // ll r = 2000;
      // for(ll c = b; a + b + c <= 2000 && M < a * b * c; c++){
      // 	ll rem = M * (a + b + c) % (a * b * c - M);
      // 	ll d = M * (a + b + c) / (a * b * c - M);
      // 	if(rem == 0 && c <= d && a + b + c + d <= 2000){
      // 	  cnt++;
      // 	  printf("%.2f %.2f %.2f %.2f\n", 
      // 		 a / 100.0, b / 100.0, c / 100.0, d / 100.0);

      // 	}
      // }
    }
  }

  //printf("%d\n", cnt);
}
