#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int t[34][34];
int digi(ll a){
	for(int d = 33; d >= 0; d--)
		if((a&(((ll)1)<<d)) > 0)
			return d+1;
}
int solve(ll a){
	if(a == 0) return 0;
	int digit, dig, ans = 0, one = 1, zero = 0;
	digit = digi(a);
	for(int i=2;i<digit;i++)for(int j=i-1;j*2>=i;j--){
		ans += t[i][j] - t[i-1][j-1];
	}
	for(int d = digit-2; d >= 0; d--){
		dig = d+1;
		if((a&(1<<d)) > 0){
			for(int j=dig-1;(j+zero+1)*2>=digit;j--){
				ans += t[dig-1][j];
			}
			one++;
		}else{
			zero++;
		}
	}
	if(zero >= one) ans++;
	return ans;
}
int main(){
	ll a,b;
	for(int i=0;i<34;i++) t[i][0] = 1;
	t[1][1] = 1;
	for(int i=2;i<34;i++)for(int j=0;j<=i;j++)
		t[i][j] = t[i-1][j]+t[i-1][j-1];
	scanf("%lld %lld", &a, &b);
	printf("%d\n", solve(b)-solve(a-1));
}