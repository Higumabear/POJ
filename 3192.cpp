#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>

using namespace std;


#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)

int inf = 100000000;

struct S{
	char s[10];
	int len;
	bool operator<(const S &r)const{
		return strcmp(s,r.s)<0;
	}
};
int n;
S in[10];

void con(char *a,int &len,S &b)
{
	int i=min(len,b.len);
	for(;i>=0;i--)
	{
		rep(j,i)if(a[len-i+j]!=b.s[j])goto FAIL;
		break; FAIL:;
	}
	for(;b.s[i];i++)a[len++]=b.s[i];
}

int main()
{
	cin>>n;
	rep(i,n)cin>>in[i].s,in[i].len=strlen(in[i].s);
	sort(in,in+n);
	
	int ans=inf;
	do
	{
		char tmp[100]; int len=0;
		rep(i,n)con(tmp,len,in[i]);
		ans=min(ans,len);
	}while(next_permutation(in,in+n));
	cout<<ans<<endl;
	
	return 0;
}
