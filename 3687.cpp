#include<cstdio>
#include<cstring>
#define maxn 210
using namespace std;
int n,m,out[maxn],q[maxn];
int i,j,k,graph[maxn][maxn];

bool Toposort(){
    for(i=n;i>=1;i--){//按编号从大到小
        for(j=n;j>=1;j--){//找质量最大的
            if(!out[j]){
                q[j]=i;
                out[j]=-1;
                break;
            }
        }//j中途退出循环,说明无零出度节点,有环
        if(j<1) return false;
        for(k=1;k<=n;k++){
            if(graph[k][j]) 
                out[k]--;
        }
    }
    return true;
}

int main(){
    int T,u,v;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        memset(graph,0,sizeof(graph));
        memset(out,0,sizeof(out));
        for(i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            if(!graph[u][v]){
                graph[u][v]=true;
                out[u]++;
            }//注意重边 
        }
        if(Toposort()){
            for(i=1;i<=n;i++){
                if(i!=n) printf("%d ",q[i]);
                else printf("%d\n",q[i]);
            }
        }
        else printf("-1\n");
    }                                                             
}
