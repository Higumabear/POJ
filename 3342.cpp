#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <vector>
 using namespace std;
 
 int n,len;
 char name[201][101];
 int dp[201][2];
 int special[201][2];
 vector <int> G[201];
 
 int max(int a,int b)
 {
     if(a > b)   return a;
     return b;
 }
 
 int find(char *str)
 {
     int i = 0;
     while(i < len && strcmp(str,name[i]) != 0)
         i++;
     if(i == len)    return -1;
     return i;
 }
 
 int insert(char *str)
 {
     strcpy(name[len],str);
     len++;
     return len - 1;
 }
 
 void init()
 {
     int i;
     for(i = 0;i <= n;i++)
         G[i].clear();
     memset(name,0,sizeof(name));
     memset(dp,0,sizeof(dp));
     memset(special,0x1,sizeof(special));
     len = 0;
 }
 
 void dfs(int v)
 {
     for(vector<int>::size_type i = 0;i < G[v].size();i++)
     {
         int u = G[v][i];//u是v的儿子节点
         dfs(u);
         dp[v][0] += max(dp[u][0],dp[u][1]);
         dp[v][1] += dp[u][0];
 
         if(dp[u][0] == dp[u][1])
             special[v][0] = 0;
         else if(dp[u][0] > dp[u][1] && special[v][0])
             special[v][0] = special[u][0];
         else if(dp[u][0] < dp[u][1] && special[v][0])
             special[v][0] = special[u][1];
         if(special[v][1])
             special[v][1] = special[u][0];
     }
     dp[v][1]++;
 }
 
 int main()
 {
     char str[101];
     while(scanf("%d",&n),n)
     {
         init();
         scanf("%s",str);
         insert(str);
         int p,q;
 
         for(int i = 1;i < n;i++)
         {
             scanf("%s",str);
             if((p = find(str)) == -1)
                 p = insert(str);
             scanf("%s",str);
             if((q = find(str)) == -1)
                 q = insert(str);
             G[q].push_back(p);
         }
 
         dfs(0);
 
         int ans = max(dp[0][1],dp[0][0]);
         printf("%d ",ans);
 
         if(dp[0][0] == dp[0][1])
             printf("No\n");
         else if(dp[0][0] == ans && special[0][0] == 0)
             printf("No\n");
         else if(dp[0][1] == ans && special[0][1] == 0)
             printf("No\n");
         else
             printf("Yes\n");
     }
     return 0;
 }