#include<stdio.h>
#include<math.h>
int main()
{
    double ka,acid,ans,ph;
    int m,n;
    scanf("%lf%lf%d%d",&ka,&acid,&m,&n);
    while(ka&&acid&&m&&n)
    {
        ans=sqrt(ka*ka+4*m*n*ka*acid);
        ans=(-ka+ans)/(2*n);
        ph=-log10(ans);
        printf("%.3lf\n",ph);
        scanf("%lf%lf%d%d",&ka,&acid,&m,&n);
    }
}