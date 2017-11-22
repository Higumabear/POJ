#include <cstdio>
#include <cstring>
#include <ctype.h>
#include <algorithm>

using namespace std;

int x[1000],y[1000];

int ret,c;
int getnum(){
  while(!isdigit(c=getchar()));
  ret=c&15;
  while(isdigit(c=getchar()))ret=(ret<<3)+(ret<<1)+(c&15);
  return ret;
}

int main(){
  int n;
  while(~scanf("%d",&n)){
    for(int i = 0; i < n; i++){
      x[i]=getnum();
      y[i]=getnum();
    }
    
    int ans=2;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < i; j++){
        int tans=2;
        int tx=x[i]-x[j];
        int ty=y[i]-y[j];
        for(int k = 0; k < j; k++)
          if((y[k]-y[j])*tx==ty*(x[k]-x[j]))++tans;
        ans=max(ans,tans);
      }
    }
    printf("%d\n",ans);
  }
}
